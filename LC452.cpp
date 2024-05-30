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
    int findMinArrowShots(vector<vector<int>> &points) {
        std::sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>& v2) -> bool {
            return v1[0] < v2[0] || v1[0] == v2[0] && v1[1] < v2[1];
        });
        int ans = 0;
        int len = points.size();
        for (int i = 0; i < len; ++i) {
            int cur = i;
            while (i + 1 < len && points[i + 1][0] <= points[cur][1]) {
                ++i;
                if (points[i][1] <= points[cur][1]) {
                    cur = i;
                }
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
