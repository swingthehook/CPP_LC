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
    int minimumSum(vector<int> &nums) {
        vector<int> pre(nums.size()), post(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre[i] = min(pre[i - 1], nums[i]);
        }
        post[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            post[i] = min(post[i + 1], nums[i]);
        }
        int ans = 1e9;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if(nums[i]>pre[i-1] && nums[i]>post[i+1])
                ans = min(ans, pre[i - 1] + nums[i] + post[i + 1]);
        }
        return ans==1e9?-1:ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {5,4,8,7,10,2};
    Solution().minimumSum(nums);
    return 0;
}
