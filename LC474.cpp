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
    int findMaxForm(vector<string> &strs, int m, int n) {
        int zeros = 0, ones = 0;
        for (char &c: strs[0]) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i >= zeros && j >= ones) {
                    dp[i][j] = 1;
                }
            }
        }
        for (int idx=1;idx<strs.size();++idx) {
            auto& str = strs[idx];
            zeros = 0;
            ones = 0;
            for (char &c: str) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            for (int i = m ; i >= zeros; --i) {
                for (int j = n ; j >= ones; --j) {
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
