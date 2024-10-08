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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //dp[i]代表加了i次油
        vector<long> dp(stations.size()+1);
        dp[0]=startFuel;
        for (int i = 0; i < stations.size(); ++i) {
            for (int j = i; j >=0 ; --j) {
                if(dp[j]>=stations[i][0]){
                    dp[j+1] = max(dp[j+1],dp[j]+stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= stations.size(); ++i) {
            if(dp[i]>=target)
                return i;
        }
        return -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
