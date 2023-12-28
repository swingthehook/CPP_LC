
#include "bits/stdc++.h"
using namespace std;
//枚举暴力
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans=1e15,sum;
        int len = nums.size();
        vector<int> cost(nums);
        for (int i = 0; i < len; i++)
        {
            sum=(long long)i*x;
            for (int j = 0; j < len; j++)
            {
                cost[j]=min(cost[j],nums[(j+i)%len]);
                sum+=cost[j];
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
