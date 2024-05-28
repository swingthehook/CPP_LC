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
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    ;
                } else if (i == 0) {
                    matrix[i][j] ^= matrix[i][j - 1];
                } else if (j == 0) {
                    matrix[i][j] ^= matrix[i - 1][j];
                } else {
                    matrix[i][j] ^= (matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1]);
                }
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                    if(matrix[i][j] >pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> mtx={{5,2},{1,6}};
    Solution().kthLargestValue(mtx,2);
    int a = 1, b = 2, c = 3;
    cout << (b ^ c);
    return 0;
}
