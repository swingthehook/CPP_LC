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
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        int i = 0;
        int minn = 1000;
        while (i < nums.size() && nums[i] < 0 && k > 0) {
            sum -= nums[i];
            --k;
            ++i;
        }
        if (k % 2 > 0) {
            if (i == 0)
                minn = nums[i];
            else if(i==nums.size())
                minn = -nums[i-1];
            else
                minn = min(nums[i], -nums[i - 1]);
            sum -= minn * 2;
        }
        while (i < nums.size()) {
            sum += nums[i];
            ++i;
        }

        return sum;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {-4,-2,-3};
    Solution().largestSumAfterKNegations(nums, 4);
    return 0;
}
