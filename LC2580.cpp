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
    static bool cmp1(const vector<int> a, const vector<int> b) {
        return a[0] < b[0];
    }

    int countWays(vector<vector<int>> &ranges) {
        sort(ranges.begin(), ranges.end(), cmp1);
        int i = 0, j = 1;
        while (j < ranges.size()) {
            while (j < ranges.size() && ranges[i][1] >= ranges[j][0]) {
                ranges[i][1] = max(ranges[i][1], ranges[j][1]);
                j++;
            }
            if (j < ranges.size()) {
                i++;
                swap(ranges[i], ranges[j]);
                j++;
            }
        }
        ++i;
        int ans = 1;
        while (i > 30) {
            ans <<= 30;
            ans %= int(1e9 + 7);
            i -= 30;
        }
        ans<<= i;
        ans%=int(1e9+7);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> ranges = {
            {1,  3},
            {
             2,  5
            },
            {
             4,  8
            },
            {
             10, 20
            }
    };
    Solution().countWays(ranges);
    return 0;
}
