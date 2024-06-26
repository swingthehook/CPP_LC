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
    bool canPartition(vector<int> &nums) {
        int len = nums.size();
        if (len < 2)
            return false;
        int sum = 0, mx = -1;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        if (sum % 2 || mx > sum / 2)
            return false;
        int target = sum / 2;
        vector<vector<bool>> dp(len, vector<bool>(target+1));
        for (int i = 0; i < len; ++i) {
            dp[i][0] = true;
            // true：可到达，可以通过之前数组的某种组合得到这个数值
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < len; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (nums[i] <= j) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len-1][target];
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
