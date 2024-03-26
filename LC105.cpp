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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie){
        if(ps==pe)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int i=is;
        while ( i < ie && inorder[i]!=root->val)
            i++;
        i-=is;
        root->left= build(preorder,inorder,ps+1,ps+1+i,is,is+i);
        root->right = build(preorder,inorder,ps+1+i,pe,is+i+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = build(preorder,inorder,0,preorder.size(),0,preorder.size());
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {3,9,20,15,7};
    Solution().buildTree(vector<int>()={3,9,20,15,7},vector<int>()={9,3,15,20,7});
    return 0;
}
