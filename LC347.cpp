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
    class mycomparison {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        for(auto ite=mp.begin();ite!=mp.end();ite++){
            pq.push(*ite);
        }
        vector<int> ans;
        while (k--){
            ans.push_back(pq.top().first);
            pq.pop();
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
