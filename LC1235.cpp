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
    bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<vector<int>> tb;
        for (int i = 0; i < startTime.size(); ++i) {
            tb.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        std::sort(tb.begin(), tb.end());
        vector<int> dp;
        int ans=-1;
        for (auto each: tb) {
            if(each[1] >= dp.size())
                dp.resize(each[1] + 1);
            int i = each[1];
            while (i > 0 && i > each[0] && dp[i] == 0) --i;
            int mx=-1;
            int j = each[0];
            for (int k = 0; k <= each[0]; ++k) {
                mx = max(mx,dp[k]);
            }
            dp[each[1]] = max(dp[i], mx + each[2]);
            ans = max(ans,dp[each[1]]);
        }

        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums1 = {4,2,4,8,2};
    vector<int> nums2 = {5,5,5,10,8};
    vector<int> nums3 = {1,2,8,10,4};
    Solution().jobScheduling(nums1, nums2, nums3);
    return 0;
}
