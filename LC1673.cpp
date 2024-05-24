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
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (!ans.empty() && len - i > k - ans.size() && nums[i] < ans.back())
                ans.pop_back();
            ans.push_back(nums[i]);
        }
        ans.resize(k);
        return ans;
    }

};

int main() {
    int num = 2;
    vector<int> nums = {3, 5, 2, 6};
    Solution().mostCompetitive(nums, 2);
    return 0;
}
