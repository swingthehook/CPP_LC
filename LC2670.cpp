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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        if(nums.size()==1){
            ans[0]=1;
            return ans;
        }
        unordered_set<int> rcd;
        vector<int> pre(nums.size()),suf(nums.size());
        pre[0]=1;
        rcd.emplace(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if(rcd.find(nums[i])!=rcd.end()){
                pre[i]=pre[i-1];
            } else{
                pre[i]=pre[i-1]+1;
                rcd.emplace(nums[i]);
            }
        }
        rcd.clear();
        rcd.emplace(nums[nums.size()-1]);
        suf[nums.size()-1]=1;
        for (int i = nums.size()-2; i >=0 ; --i) {
            if(rcd.find(nums[i])!=rcd.end()){
                suf[i]=suf[i+1];
            }else{
                suf[i]=suf[i+1]+1;
                rcd.emplace(nums[i]);
            }
        }
        ans[0] = pre[0]-suf[1];
        ans[nums.size()-1] = pre[nums.size()-1];
        for (int i = 1; i < nums.size()-1; ++i) {
            ans[i]=pre[i]-suf[i+1];
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
