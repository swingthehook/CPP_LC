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

    int findTargetSumWays(vector<int> &nums, int target) {
        vector<int> v1(2001);
        v1[1000 + nums[0]] += 1;
        v1[1000 - nums[0]] += 1;
        int minn = 1000 - nums[0];
        int maxn = 1000 + nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            vector<int> v2(2001);
            for (int j = minn; j <= maxn; ++j) {
                v2[j - nums[i]] += v1[j];
                v2[j + nums[i]] += v1[j];
            }
            minn -= nums[i];
            maxn += nums[i];
            swap(v1, v2);
//            cout<<minn-1000<<' '<<maxn-1000<<endl;
//            for (int j = minn; j <= maxn; ++j) {
//                cout<<v1[j]<<' ';
//            }
//            cout<<endl;
        }
        return v1[target + 1000];
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3);
    return 0;
}
