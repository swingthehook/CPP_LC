
#include "bits/stdc++.h"

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
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        vector<int> ans;
        ans.reserve(len);
        if(nums[0]>=0){
            for (int i = 0; i < len; i++)
            {
                ans.push_back(nums[i]*nums[i]);
            }
            
        }
        else if(nums[len-1]<=0){
            for (int i = len-1; i >=0; --i){
                ans.push_back(nums[i]*nums[i]);
            }
        }
        else{
            for (int i = 0; i < len; i++)
            {
                if(nums[i]<0)
                    nums[i]=-nums[i];
                else
                    break;
            }
            sort(nums.begin(),nums.end());
            for (int i = 0; i < len; i++)
            {
                ans.push_back(nums[i]*nums[i]);
            }
        }
        return ans;
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> words = {"one.two.three","four.five","six"};
    char separator='.';
    string s2 = "abc";
    Solution().splitWordsBySeparator(words,separator);
    return 0;
}
