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
    vector<int> partitionLabels(string s) {
        int first[26] = {0}, latest[26] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            latest[s[i] - 'a'] = i;
        }
        for (int i = len - 1; i >= 0; --i) {
            first[s[i] - 'a'] = i;
        }
        vector<vector<int>> grid;
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1) {
                grid.push_back({first[i], latest[i]});
            }
        }
        vector<int> ans;
        sort(grid.begin(), grid.end(), [](vector<int> v1, vector<int> v2) -> bool {
            return v1[0] < v2[0];
        });
        int left = grid[0][0], right = grid[0][1];
        for (int i = 1; i < grid.size(); ++i) {
            if (grid[i][0] > right) {
                ans.push_back(right - left + 1);
                left = grid[i][0];
                right = grid[i][1];
            } else {
                right = max(right, grid[i][1]);
            }
        }
        ans.push_back(right - left + 1);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
