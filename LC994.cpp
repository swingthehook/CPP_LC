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
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int unrotted = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    unrotted++;
                } else if (grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }
        vector<vector<bool>> visit(m, vector<bool>(n));
        int days = 0;
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int i = tmp.first.first, j = tmp.first.second;
            if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visit[i - 1][j]) {
                q.push(make_pair(make_pair(i - 1, j), tmp.second + 1));
                visit[i - 1][j] = true;
                unrotted--;
            }
            if (i + 1 < m && grid[i + 1][j] == 1 && !visit[i + 1][j]) {
                q.push(make_pair(make_pair(i + 1, j), tmp.second + 1));
                visit[i + 1][j] = true;
                unrotted--;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visit[i][j - 1]) {
                q.push(make_pair(make_pair(i, j - 1), tmp.second + 1));
                visit[i][j - 1] = true;
                unrotted--;
            }
            if (j + 1 < n && grid[i][j + 1] == 1 && !visit[i][j + 1]) {
                q.push(make_pair(make_pair(i, j + 1), tmp.second + 1));
                visit[i][j + 1] = true;
                unrotted--;
            }
            days = tmp.second;
        }
        return unrotted == 0 ? days : -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> grid = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
    };
    Solution().orangesRotting(grid);
    return 0;
}
