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
    int longestEqualSubarray(vector<int> &nums, int k) {
        int max_cnt = 0;
        int i = 0, j = 0;
        map<int, int> mp;
        while (j < nums.size()) {
            while (j < nums.size() && j - i <= max_cnt + k) {
                mp[nums[j]]++;
                max_cnt = max(max_cnt, mp[nums[j]]);
                j++;
            }
            mp[nums[i]]--;
            ++i;
            if (j < nums.size()) {
                mp[nums[j]]++;
                max_cnt = max(max_cnt, mp[nums[j]]);
                ++j;
            }


        }
        return max_cnt;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {3, 2, 4, 2};
    Solution().longestEqualSubarray(nums, 1);
    return 0;
}
