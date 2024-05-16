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
    int maxSubArray(vector<int>& nums) {
        int mx = INT32_MIN;
        int sum=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum+=nums[i];
            mx = max(mx,sum);
            if(sum<0)
                sum=0;
        }
        return mx;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1};
    Solution().maxSubArray(nums);
    return 0;
}
