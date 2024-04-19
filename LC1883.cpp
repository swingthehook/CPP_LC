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
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        //浮点数计算过程中可能会有eps的bias，后续计算要加上或者减去epsilon，消除误差
        double eps = 1e-7;
        double mx = hoursBefore+eps;
        int sz = dist.size();
        vector<vector<double>> dp(sz + 1, vector<double>(sz + 1));
        //i:走过了几步，j：跳过了几次
        //只管本次这一步是否跳过，而不是上一步之后
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = ceil(dp[i - 1][j] + (double) dist[i - 1] / (double) speed - eps);
                if (j) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (double) dist[i - 1] / (double) speed);
                }
            }
            dp[i][i] = dp[i-1][i-1] + (double) dist[i - 1] / (double) speed;
        }
        for (int i = 0; i < dp[0].size(); ++i) {
            if (dp[dist.size()][i] <= mx)
                return i;
        }
        return -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,3,5,5};
    Solution().minSkips(nums,1,10);
    return 0;
}
