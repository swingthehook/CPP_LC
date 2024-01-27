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
    //四重循环->两个二重循环
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //计数而不是直接emplace数值本身
        unordered_map<int,int> us;
        for(int num1:nums1){
            for(int num2:nums2){
                us[num1+num2]++;
            }
        }
        int ans=0;
        for(int num3:nums3){
            for(int num4:nums4){
                if(us[-num3-num4])
                    ans+=us[-num3-num4];
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    cout << "sfgddxb"<<endl;
    return 0;
}
