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
    int jump(vector<int> &nums) {
        int maxreach = 0;
        int last_mxreach;
        int ans = 0;
        for (int i = 0; i < nums.size(); ) {
            if (maxreach >= nums.size() - 1)
                return ans;
            if (i + nums[i] > maxreach) {
                ans++;
                last_mxreach = maxreach;
                for (; i <= last_mxreach && i < nums.size(); ++i) {
                    maxreach = max(maxreach, i + nums[i]);
                }
            }else{
                ++i;
            }

        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution().jump(nums);
    return 0;
}
