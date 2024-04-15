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
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum = 0;

    void rec(int start, int target_sum, int index, int k) {
        if (index == k - 1) {
            int left = target_sum - sum;
            if (left >= start && left <= 9) {
                tmp[index] = left;
                ans.push_back(tmp);
            }
        } else {
            for (int i = start; i < (target_sum - sum) * (k - index); ++i) {
                sum += i;
                tmp[index] = i;
                rec(i + 1, target_sum, index + 1, k);
                sum -= i;
            }
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        tmp.resize(k);
        rec(1, n, 0, k);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().combinationSum3(3,9);
    return 0;
}
