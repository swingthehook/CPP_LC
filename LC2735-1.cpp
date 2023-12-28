
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans=1e9,sum;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            sum=i*x;
            for (int j = 0; j < len; j++)
            {
                sum+=min(nums[j],nums[(j+i)%len]);
            }
            ans = sum<ans?sum:ans;
        }
        return ans;
    }
};

int main() {
    
    vector<int> p = {20,1,5};
    Solution().minCost(p,5);

    return 0;
}
