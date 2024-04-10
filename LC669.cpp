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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root)
            return root;
        //root
        while (root && root->val > high)
            root = root->left;
        while (root && root->val < low)
            root = root->right;
        //left subtree
        bool done = false;
        auto tmp = root;
        while (!done) {
            if(!tmp)
                done = true;
            else if (tmp->left && tmp->left->val > low)
                tmp = tmp->left;
            else {
                tmp->left = NULL;
                done = true;
            }
        }
        //right subtree
        done = false;
        tmp = root;
        while (!done) {
            if (tmp->right && tmp->right->val < high)
                tmp = tmp->right;
            else{
                tmp->right = NULL;
                done = true;
            }
        }
        return root;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    TreeNode *root = new TreeNode(1,new TreeNode(0),new TreeNode(2));
    Solution().trimBST(root,1,2);
    return 0;
}
