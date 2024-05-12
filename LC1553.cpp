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
    map<int, int> mp;

    int minDays(int n) {
        if (n < 2)
            return n;
        int way1, way2;
        if (mp.find(n / 2) == mp.end()) {
            mp[n / 2] = minDays(n / 2);
        }
        if (mp.find(n / 3) == mp.end()) {
            mp[n / 3] = minDays(n / 3);
        }
        return min(mp[n / 2] + 1 + n % 2, mp[n / 3] + 1 + n % 3);
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    cout << Solution().minDays(10);
    return 0;
}
