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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        vector<int> ans(2);
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        for (auto &row: grid)
            for (auto &col: row) {
                cnt[col]++;
            }
        int sz = cnt.size();
        for (int i = 1; i < sz; ++i) {
            if (cnt[i] == 2) {
                ans[0] = i;
            } else if (cnt[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> grid = {
            {1, 3},
            {2, 2}
    };
    Solution().findMissingAndRepeatedValues(grid);
    return 0;
}
