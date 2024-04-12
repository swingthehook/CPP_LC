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
    int findChampion(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            int tmp = std::accumulate(grid[i].begin(), grid[i].end(),0);
            if(tmp == grid.size()-1)
                return i;
        }
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    vector<vector<int>>grid = {
            {0,1},
            {0,0}
    };
    Solution().findChampion(grid);
    return 0;
}
