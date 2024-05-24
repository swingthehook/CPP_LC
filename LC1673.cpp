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
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            bool f1, f2, f3;
            f1 = !ans.empty();
            if (f1) {
                int t1 = len - i + ans.size();
                k - ans.size();
                int t2 = k - ans.size();
                f2 = t1 > t2;
                if (f2)
                    f3 = nums[i] < ans.back();
            }

            while (f1 && f2 && f3) {
                ans.pop_back();
                f1 = !ans.empty();
                if (f1) {
                    int t1 = len - i + ans.size();
                    int t2 = k;
                    f2 = t1 > t2;
                    if (f2)
                        f3 = nums[i] < ans.back();
                }
            }
            ans.push_back(nums[i]);
        }
        ans.resize(k);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {71, 18, 52, 29, 55, 73, 24, 42, 66, 8, 80, 2};
    Solution().mostCompetitive(nums, 3);
    return 0;
}
