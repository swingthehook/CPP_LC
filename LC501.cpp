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
    vector<int> ans;
    int maxcnt = -1;
    int cnt = 0;
    int last=-1e6;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if(root->val != last) {
            cnt = 1;
            last = root->val;
        }else{
            cnt++;
        }
        if(cnt > maxcnt){
            maxcnt=cnt;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(cnt == maxcnt){
            ans.push_back(root->val);
        }
        inorder(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        inorder(root);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
