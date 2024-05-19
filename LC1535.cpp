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
    int getWinner(vector<int> &arr, int k) {
        if (k >= arr.size()) {
            int mx = -1;
            for (int i = 0; i < arr.size(); ++i) {
                mx = max(mx, arr[i]);
            }
            return mx;
        } else {
            int cnt = 0;
            int pre = -1;
            for (int i = 0; i < 2; ++i) {
                for (int i = 0; i < arr.size(); ++i) {
                    if (pre == -1) {
                        cnt = 0;
                        pre = arr[i];
                    } else if (arr[i] < pre) {
                        cnt++;
                    } else {
                        cnt = 1;
                        pre = arr[i];
                    }
                    if (cnt == k)
                        return pre;
                }
            }

        }
        return -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 1, 3, 5, 4, 6, 7};
    Solution().getWinner(nums, 2);
    return 0;
}
