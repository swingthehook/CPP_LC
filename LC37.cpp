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
    vector<set<char>> block, rows, cols;
    vector<vector<char>> *bd;
    bool find = false;

    void dfs(int row, int col) {
        if (row == 9)
            find = true;
        if (find)
            return;
        if ((*bd)[row][col] == '.') {
            for (char c = '1'; c <= '9'; ++c) {
                int blk = (row / 3) * 3 + (col / 3);
                if (block[blk].find(c) == block[blk].end()
                    && rows[row].find(c) == rows[row].end()
                    && cols[col].find(c) == cols[col].end()) {
                    (*bd)[row][col] = c;
                    block[blk].emplace(c);
                    rows[row].emplace(c);
                    cols[col].emplace(c);
                    if (col == 8)
                        dfs(row + 1, 0);
                    else
                        dfs(row, col + 1);
                    if (find)
                        return;
                    (*bd)[row][col] = '.';
                    block[blk].erase(c);
                    rows[row].erase(c);
                    cols[col].erase(c);
                }
            }
        } else {
            if (col == 8)
                dfs(row + 1, 0);
            else
                dfs(row, col + 1);
        }
    }

    void solveSudoku(vector<vector<char>> &board) {
        bd = &board;
        block.resize(9);
        rows.resize(9);
        cols.resize(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int blk = int(i / 3) * 3 + int(j / 3);
                    //cout<<i<<" "<<j<<" "<<blk<<endl;
                    block[blk].emplace(board[i][j]);
                    rows[i].emplace(board[i][j]);
                    cols[j].emplace(board[i][j]);
                }
            }
        }
        dfs(0, 0);
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<char>> matrix = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution().solveSudoku(matrix);
    return 0;
}
