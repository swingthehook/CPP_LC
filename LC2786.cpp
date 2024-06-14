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
    long long maxScore(vector<int> &nums, int x) {
        long long ans=nums[0];
        vector<long long > dp(2,INT32_MIN);
        dp[nums[0]%2] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int odev = nums[i]%2;
            long long cur = max(dp[odev]+nums[i],dp[1-odev]+nums[i]-x);
            ans = max(ans,cur);
            dp[odev] = max(dp[odev],cur);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {38,92,23,30,25,96,6,71,78,77,33,23,71,48,87,77,53,28,6,20,90,83,42,21,64,95,84,29,22,21,33,36,53,51,85,25,80,56,71,69,5,21,4,84,28,16,65,7};
    Solution().maxScore(nums, 52);
    return 0;
}
