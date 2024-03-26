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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    TreeNode* build(vector<int>& nums,int st,int ed){
        if(st == ed)
            return NULL;
        int max = -1,maxidx = -1;
        for(int i=st;i<ed;i++){
            if(nums[i]>max){
                max = nums[i];
                maxidx = i;
            }
        }
        TreeNode *root = new TreeNode(max);
        root->left = build(nums,st,maxidx);
        root->right = build(nums,maxidx+1,ed);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *ans = build(nums,0,nums.size());
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
