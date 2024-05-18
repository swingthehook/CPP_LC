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
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        std::sort(divisors.begin(), divisors.end(), greater<int>());
        int mxtimes = 0;
        int ans = divisors[0];
        for (int i = 0; i < divisors.size(); ++i) {
            int times = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] % divisors[i] == 0)
                    times++;

            }
            if (times >= mxtimes) {
                mxtimes = times;
                ans = divisors[i];
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {56, 22, 79, 41, 8, 39, 81, 59, 74, 14, 45, 49, 15, 10, 28, 16, 77, 22, 65, 8, 36, 79, 94, 44,
                        80, 72, 8, 96, 78};
    vector<int> nums2 = {39, 92, 69, 55, 9, 44, 26, 76, 40, 77, 16, 69, 40, 64, 12, 48, 66, 7, 59, 10, 33, 72, 97, 60,
                         79, 68, 25, 63};
    Solution().maxDivScore(nums, nums2);
    return 0;
}
