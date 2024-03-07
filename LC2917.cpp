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
    int findKOr(vector<int> &nums, int k) {
        int ans = 0;
        int count[32] = {0};
        for (int tmp: nums) {
            int num=tmp;
            int i = 0;
            while (num > 0) {
                count[i] += num & 1;
                num = num >> 1;
                ++i;
            }
        }
        for (int i = 0; i < 31; ++i) {
            ans += count[i] >= k ? 1 << i : 0;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution().findKOr(nums,4);
    return 0;
}
