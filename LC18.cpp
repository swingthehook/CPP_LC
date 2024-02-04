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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 && nums[0] > target) return ans;
        if (nums.back() < 0 && nums.back() < target) return ans;
        int len = nums.size();
        for (int i = 0; i < len - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len - 2; ++j) {
                if (nums[i] + nums[j] > 0 && nums[i] + nums[j] > target)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = len - 1;
                while (left < right) {
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long) nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left + 1] == nums[left]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else left++;
                }
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 2, 2, 2};
    Solution().fourSum(nums, 8);
    return 0;
}
