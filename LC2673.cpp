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
    int minIncrements(int n, vector<int> &cost) {
        int ans = 0;
        int idx = n - 1;
        while (idx > 0) {
            if (cost[idx] > cost[idx - 1]) {
                ans += (cost[idx] - cost[idx - 1]);
                cost[idx / 2 - 1] += cost[idx];
            } else {
                ans += (cost[idx - 1] - cost[idx]);
                cost[idx / 2 - 1] += cost[idx - 1];
            }
            idx -= 2;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,5,2,2,3,3,1};
    Solution().minIncrements(7,nums);
    return 0;
}
