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
    //后缀和，从后往前遍历即可
    //二叉树从后向前遍历，即LNR变成RNL，交换访问左右子树的语句即可
    int sum=0;
    bool process= false;
    void inorder(TreeNode* root){
        if(root->right)
            inorder(root->right);
        sum+=root->val;
        root->val=sum;
        if(root->left)
            inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        inorder(root);
        return root;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
