#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        int idx1 = 0, idx0 = 0;
        for (; idx1 < k; ++idx1) {
            while (!q.empty() && nums[idx1] > q.back())
                q.pop_back();
            q.push_back(nums[idx1]);
        }
        vector<int> ans(nums.size()-k+1);
        while(idx1<nums.size()){
            ans[idx0]=q.front();
            if(nums[idx0] == q.front())
                q.pop_front();
            idx0++;
            while (!q.empty() && nums[idx1] > q.back())
                q.pop_back();
            q.push_back(nums[idx1]);
            idx1++;
        }
        ans.pop_back();
        ans.push_back(q.front());
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,3,1,2,0,5};
    Solution().maxSlidingWindow(nums,3);
    return 0;
}
