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

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int ans = 0;

    void dfs(vector<int> &nums, int begin, int end, int target, int cnt) {
        if (begin + 1 <= end && nums[begin] + nums[begin + 1] == target) {
            dfs(nums, begin + 2, end, target, cnt + 1);
        }
        if (begin < end && nums[begin] + nums[end] == target) {
            dfs(nums, begin + 1, end - 1, target, cnt + 1);
        }
        if (end - 1 >= begin && nums[end - 1] + nums[end] == target) {
            dfs(nums, begin, end - 2, target, cnt + 1);
        }
        ans = max(ans, cnt);


    }

    int maxOperations(vector<int> &nums) {
        int len = nums.size();
        set<int> list;
        list.emplace(nums[0] + nums[1]);
        list.emplace(nums[len - 1] + nums[len - 2]);
        list.emplace(nums[0] + nums[len - 1]);
        for (auto &each: list) {
            dfs(nums, 0, len - 1, each, 0);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1, 1, 2, 3, 2, 2, 1, 3, 3};
    Solution().maxOperations(nums);
    return 0;
}
