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
    /*
     * 把数值对应的下标收集起来，然后计算把整个数组变成这个数要花的时间
     * */
    int minimumSeconds(vector<int>& nums) {
        int ans=1e9;
        unordered_map<int,vector<int>> rcd;
        for (int i = 0; i < nums.size(); ++i) {
            rcd[nums[i]].push_back(i);
        }
        for(auto ite:rcd){
            int tmp=ite.second[0]+nums.size()-ite.second.back();
            for (int i = 1; i < ite.second.size(); ++i) {
                tmp = max(tmp,ite.second[i]-ite.second[i-1]);
            }
            ans = min(ans,tmp/2);
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
