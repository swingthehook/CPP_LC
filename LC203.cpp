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
    int alternatingSubarray(vector<int> &nums) {
        int count = -1;
        int ans = -1;
        int flag;
        for (int i = 1; i < nums.size();) {
            if (nums[i] == nums[i - 1] + 1) {
                flag = 1;
                count = 1;
                while (i<nums.size() && nums[i] - nums[i-1] == flag){
                    i++;
                    flag = - flag;
                    count++;
                }
                ans = max(ans , count);
            }else{
                ++i;
            }
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
