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
    vector<TreeNode *> pathp, pathq, tmp;
    //dfs记录路径，然后在路径上查找LCA
    void dfs(TreeNode *root, int depth, TreeNode *p, TreeNode *q) {
        if (tmp.size() <= depth) {
            tmp.push_back(root);
        } else {
            tmp[depth] = root;
        }
        if (root == p) {
            pathp = tmp;
            pathp.resize(depth + 1);
        }
        if (root == q) {
            pathq = tmp;
            pathq.resize(depth + 1);

        }
        if (root->left)
            dfs(root->left, depth + 1, p, q);
        if (root->right)
            dfs(root->right, depth + 1, p, q);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, 0, p, q);
        int len = min(pathp.size(), pathq.size()), i = 0;

        while (i < len && pathp[i] == pathq[i])
            ++i;
        return pathp[i - 1];

    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
