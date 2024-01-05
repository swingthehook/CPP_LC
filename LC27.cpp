
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
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int len=nums.size();
        while(j<len){
            while (j<len&&nums[j] == val) j++;
            if(j<len){
                nums[i]=nums[j];
                ++i;++j;
            }

        }
        return i;
    }
};

int main() {

    vector<int> p = {0,1,2,2,3,0,4,2};
    string s1 = "ecbafedcba";
    string s2 = "abcdef";
    auto ans = Solution().removeElement(p,2);
    for (int i = 0; i < ans; ++i) {
        cout<<p[i]<<' ';
    }

    return 0;
}
