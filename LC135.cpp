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
    int candy(vector<int> &ratings) {
        if(ratings.size()==1)
            return 1;
        int idx1 = 0, idx2 = 1;
        int last_start_given = 0;
        int ans = 0;
        while (idx2 < ratings.size()) {
            if (idx2 < ratings.size() && ratings[idx2] > ratings[idx2-1]) {
                while (idx2 < ratings.size() && ratings[idx2] > ratings[idx2-1])
                    idx2++;
                idx2--;
                if (last_start_given == 0) ans++;
                int len = idx2 - idx1 + 1;
                ans += (float)(len + 1) / 2.0 * len - 1;
                last_start_given = len;
                idx1 = idx2;
                idx2++;
            } else if (idx2 < ratings.size() && ratings[idx2] < ratings[idx2-1]) {
                while (idx2 < ratings.size() && ratings[idx2] < ratings[idx2-1])
                    idx2++;
                idx2--;
                int len = idx2 - idx1 + 1;
                if (last_start_given < len) {
                    ans += len - last_start_given;
                }
                ans += (float)len / 2 * (len - 1);
                last_start_given=1;
                idx1=idx2;
                idx2++;
            } else {
                if(last_start_given==0)
                    ans++;
                ans++;
                last_start_given = 1;
                idx1++;
                idx2++;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {10,10,10,10,10,10};
    Solution().candy(nums);
    return 0;
}
