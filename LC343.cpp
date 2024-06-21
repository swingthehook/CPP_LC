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
    int integerBreak(int n) {
        int ans = 0;
        if (n == 2 || n == 3)
            return n - 1;
        for (int k = 2; k <= n; k++) {
            int smaller = n / k;
            int bigger = smaller + 1;
            int res = 1;
            int tmp = n;
            while (tmp % bigger) {
                res *= smaller;
                tmp -= smaller;
            }
            while (tmp) {
                res *= bigger;
                tmp -= bigger;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().integerBreak(10);
    return 0;
}
