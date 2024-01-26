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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int map[1001]={0};
        for(int num:nums1){
            map[num]=1;
        }
        for(int num:nums2){
            if(map[num]==1){
                ans.push_back(num);
                map[num]=0;
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
