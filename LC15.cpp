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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int left = i+1;
            int right = nums.size()-1;
            while (left<right){
                int temp = nums[i]+nums[left]+nums[right];
                if(temp>0)
                    right--;
                else if(temp == 0){
                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while (left<right && nums[left] == nums[left+1]) left++;
                    while (left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else
                    left++;

            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
