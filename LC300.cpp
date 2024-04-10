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
    int lengthOfLIS(vector<int>& nums) {
        int ans=1;
        vector<int> dp(nums.size(),1);
        dp[0]=1;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i-1; j>=0 ; --j) {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    Solution().lengthOfLIS(nums);
    return 0;
}
