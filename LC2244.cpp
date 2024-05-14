#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        map<int, int> mp;
        int ans = 0;
        for (int each: tasks) {
            mp[each]++;
        }
        for (auto ite = mp.begin(); ite != mp.end(); ++ite) {
            int times = ite->second;
            if (times == 1)
                return -1;
            if (times % 3 == 0)
                ans += times / 3;
            else if (times % 3 == 1) {
                ans += 2 + (times - 4) / 3;
            } else {
                ans+= 1 + (times-2)/3;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    Solution().minimumRounds(nums);
    return 0;
}
