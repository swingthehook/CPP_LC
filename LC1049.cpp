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
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0, maxval = -1;
        for (auto &ele: stones) {
            sum += ele;
            maxval = max(maxval, ele);
        }

        if (maxval > sum / 2) {
            return 2 * maxval - sum;
        } else if (maxval == sum / 2) {
            return 0;
        } else {
            vector<bool> dp1(sum / 2 + 1), dp2(sum / 2 + 1);
            dp1[0] = true;
            dp1[stones[0]] = true;
            for (int i = 1; i < stones.size(); ++i) {
                for (int j = 0; j < sum / 2 + 1; ++j) {
                    if (j == 0) {
                        dp2[j] = true;
                    } else if (j >= stones[i]) {
                        dp2[j] = dp1[j] | dp1[j - stones[i]];
                    } else {
                        dp2[j] = dp1[j];
                    }
                }
                swap(dp1, dp2);
            }
            for (int i = sum / 2; i >= 0; --i) {
                if (dp1[i]){
                    return sum-2*i;
                }
            }
        }
        return 0;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2,7,4,1,8,1};
    Solution().lastStoneWeightII(nums);
    return 0;
}
