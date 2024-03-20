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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *ans = build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return ans;
    }

    TreeNode *build(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2) {
        if(s1==e1)
            return NULL;
        TreeNode *root = new TreeNode(postorder[e2-1]);
        int i;
        for(i=s1;i<e1;++i){
            if(inorder[i] == postorder[e2-1])
                break;
        }
        root->left = build(inorder,s1,i,postorder,s2,s2+i-s1);
        root->right = build(inorder,i+1,e1,postorder,s2+i-s1,e2-1);
        return root;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().buildTree(vector<int>()={9,3,15,20,7},vector<int>()={9,15,7,20,3});
    return 0;
}
