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
    //有点暴力
    vector<int> path;
    int ans=-1;
    void dfs(TreeNode *root,int depth){
        if(depth){
            if(path.size()<=depth)
                path.emplace_back(root->val);
            else
                path[depth]=root->val;
            for (int i = 0; i < depth; ++i) {
                ans = max(ans, abs(path[i]-root->val));
            }
        }
        if(root->left)
            dfs(root->left,depth+1);
        if(root->right)
            dfs(root->right,depth+1);
    }
    int maxAncestorDiff(TreeNode* root) {
        path.emplace_back(root->val);
        dfs(root,0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
