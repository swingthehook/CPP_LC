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
    vector<vector<string>> ans;
    vector<string> tmp;
    vector<bool> col, right, left;
    int sz;

    void rec(int start) {
        if (start == sz)
            ans.push_back(tmp);
        for (int i = 0; i < sz; ++i) {
            if (!col[i] && !left[start + i] && !right[start - i + sz - 1]) {
                tmp[start][i] = 'Q';
                col[i] = true;
                left[start + i] = true;
                right[start - i + sz - 1] = true;
                rec(start + 1);
                tmp[start][i] = '.';
                col[i] = false;
                left[start + i] = false;
                right[start - i + sz - 1] = false;
            }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        sz = n;
        col.resize(n);
        left.resize(2 * n - 1);
        right.resize(2 * n - 1);
        tmp = vector<string>(n, string(n, '.'));
        rec(0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().solveNQueens(4);
    return 0;
}
