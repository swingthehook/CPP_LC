
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;
        while (left<=right){
            mid = (left+right)/2;
            if (nums[mid]==target) return mid;
            else if(nums[mid]<target) left = mid+1;
            else if(nums[mid]>target) right = mid-1;
        }
        return -1;
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
