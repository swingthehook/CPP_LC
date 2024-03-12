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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        int cur = 0;
        ans.push_back(vector<int>());
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            for (auto son: tmp.first->children)
                q.push(make_pair(son, tmp.second + 1));
            if (tmp.second != cur) {
                cur++;
                ans.push_back(vector<int>());
            }
                ans[tmp.second].push_back(tmp.first->val);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().findKOr(nums, 4);
    return 0;
}
