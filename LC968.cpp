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
    int ans = 0;
    void post(TreeNode *root) {
        if (root->left) {
            post(root->left);
        }
        if (root->right) {
            post(root->right);
        }
        if(root->left &&root->left->val==0||root->right&&root->right->val==0){
            root->val=1;
            if(root->left)
                root->left->val=2;
            if(root->right)
                root->right->val=2;
            ans++;
        }
        if(root->left && root->left->val==1) {
            root->left->val = 2;
            root->val=2;
        }
        if(root->right && root->right->val==1){
            root->right->val=2;
            root->val=2;
        }
    }

    int minCameraCover(TreeNode *root) {
        post(root);
        if(root->val==0)
            ans++;
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
