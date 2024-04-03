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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if(!root)
            return new TreeNode(val);
        auto tmp = root;
        while (1) {
            if (tmp->val > val){
                if(tmp->left)
                    tmp=tmp->left;
                else{
                    auto nd = new TreeNode(val);
                    tmp->left=nd;
                    return root;
                }
            }else{
                if(tmp->right)
                    tmp=tmp->right;
                else{
                    auto nd = new TreeNode(val);
                    tmp->right=nd;
                    return root;
                }
            }
        }
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
