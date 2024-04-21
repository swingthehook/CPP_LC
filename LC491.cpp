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
    vector<vector<int>> ans;
    vector<int> tmp;
    set<vector<int>> st;
    void rec(vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            if (tmp.size() > 1 && st.find(tmp)==st.end()){
                ans.push_back(tmp);
                st.emplace(tmp);
            }
            return;
        }
        rec(nums, cur + 1);
        if (tmp.empty()||nums[cur] >= tmp.back()) {
            tmp.push_back(nums[cur]);
            rec(nums, cur + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        rec(nums, 0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {4, 6, 7, 7};
    Solution().findSubsequences(nums);
    return 0;
}
