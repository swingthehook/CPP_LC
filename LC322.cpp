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
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<int> dp(amount+1,1e9);
        for(auto i : coins){
            if(i<=amount)
                dp[i] = 1;
        }
        for (int i = 1; i < amount + 1; ++i) {
            if(dp[i] == 1)
                continue;
            for(auto j: coins){
                if(i-j >0){
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        return dp.back() == 1e9?-1:dp.back();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,2,5};
    Solution().coinChange(nums,11);
    return 0;
}
