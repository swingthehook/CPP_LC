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
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            mp.emplace(make_pair(nums[i],i));
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {3,3};
    Solution().twoSum(nums,6);
    cout << "sfgddxb" << endl;
    return 0;
}
