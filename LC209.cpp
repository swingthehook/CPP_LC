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
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int ans=1e9;
        int len = nums.size();
        int sum=0;
        for(;j<len;){
            if(sum>=target){
                ans = min(ans,j-i);
                sum-=nums[i];
                i++;
            }else{
                sum+=nums[j];
                j++;
            }
        }
        while (i<len){
            if(sum>=target){
                ans = min(ans,j-i);
                sum-=nums[i];
                i++;
            } else
                break;
        }
        return ans==1e9?0:ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    auto ans = Solution().generateMatrix(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
