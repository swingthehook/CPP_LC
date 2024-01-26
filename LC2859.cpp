#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int ans = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {

            if (__builtin_popcount(i) == k)
                ans += nums[i];
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    auto ans = Solution().alternatingSubarray(nums);
    cout << ans;
    return 0;
}
