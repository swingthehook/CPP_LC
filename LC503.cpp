
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> st(len);
        vector<int> ans(len,-1);
        int sp=-1;
        for (int i = 0; i < len; i++)
        {
            while (sp>=0&&nums[st[sp]] < nums[i])
            {
                ans[st[sp]]=nums[i];
                sp--;
            }
            st[++sp]=i;
        }
        for (int i = 0; i < len; i++)
        {
            while (sp>=0&&nums[st[sp]] < nums[i])
            {
                ans[st[sp]]=nums[i];
                sp--;
            }
            st[++sp]=i;
        }
        return ans;
    }
};


int main() {
    
    vector<int> p = {5,4,3,2,1};
    auto ans = Solution().nextGreaterElements(p);
    for(auto elem:ans){
        cout<<elem<<",";
    }
    
    return 0;
}
