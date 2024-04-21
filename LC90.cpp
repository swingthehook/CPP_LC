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
    vector<int> tmp;
    vector<vector<int>> ans;

    void rec(vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        int tail = cur + 1;
        while (tail < nums.size() && nums[tail] == nums[cur]) tail++;
        //确定重复数字的范围
        rec(nums, tail); //不选
        for (int i = cur; i < tail; ++i) {  //重复数字从不选到全选
            tmp.push_back(nums[cur]);
            rec(nums, tail);
        }
        for (int i = cur; i < tail; ++i) {
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        rec(nums, 0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,2,2};
    Solution().subsetsWithDup(nums);
    return 0;
}
