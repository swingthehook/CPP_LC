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
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        vector<int> ans;
        int sum = 0;
        int m = rolls.size();
        int total = mean * (m + n);
        for (int i = 0; i < m; ++i) {
            sum += rolls[i];
        }
        if (sum + n * 6 < total || sum + n > total)
            return ans;
        total -= sum;
        int smaller = total / n;
        int bigger_cnt = total % n;
        ans.resize(n);
        std::fill(ans.begin(), ans.begin() + n - bigger_cnt, smaller);
        std::fill(ans.begin() + n - bigger_cnt, ans.end(), smaller + 1);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {4, 5, 6, 2, 3, 6, 5, 4, 6, 4, 5, 1, 6, 3, 1, 4, 5, 5, 3, 2, 3, 5, 3, 2, 1, 5, 4, 3, 5, 1, 5};
    Solution().missingRolls(nums, 4, 40);
    return 0;
}
