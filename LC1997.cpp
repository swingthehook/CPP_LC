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
    //由于nextvisit保证了一定会向前跳，所以到达i时，前面所有房间都是偶数次访问
    //迭代方式：到达i，必须两次到达i-1，第一次正常到达i-1，第二次是从nextvisit[i-1]过去
    //第一次代价为dp[i-1]，第二次代价为dp[i-1]-dp[to]，to=nextvisit[i-1]
    int firstDayBeenInAllRooms(vector<int> &nextVisit) {
        long long int *dp = new long long[nextVisit.size()];
        dp[0] = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < nextVisit.size(); ++i) {
            dp[i] = (dp[i - 1] + dp[i - 1] - dp[nextVisit[i - 1]] + 2 + mod) % mod;
        }
        return int(dp[nextVisit.size() - 1] % mod);
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
