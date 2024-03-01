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

class Solution {
public:
    bool valid2(int a, int b) {
        return a == b;
    }

    bool valid3(int a, int b, int c) {
        return a == b && b == c || a == b - 1 && c == b + 1;
    }

    bool validPartition(vector<int> &nums) {
        vector<bool> dp(nums.size() + 1, false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = valid2(nums[0], nums[1]);
        for (int i = 3; i <= nums.size(); ++i) {
            dp[i] = dp[i - 2] && valid2(nums[i - 1], nums[i - 2])
                    || dp[i - 3] && valid3(nums[i - 3], nums[i - 2], nums[i - 1]);
        }
        return dp.back();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
