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
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int max_m = 0, max_p = 0, max_g = 0;
        int cnt_m = 0, cnt_p = 0, cnt_g = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            for (char c: garbage[i]) {
                if (c == 'M') {
                    max_m = i;
                    cnt_m++;
                } else if (c == 'P') {
                    max_p = i;
                    cnt_p++;
                } else {
                    max_g = i;
                    cnt_g++;
                }
            }
            if (i > 1)
                travel[i - 1] += travel[i - 2];
        }
        return (max_m == 0 ? 0 : travel[max_m - 1]) + (max_p == 0 ? 0 : travel[max_p - 1]) +
               (max_g == 0 ? 0 : travel[max_g - 1]) + cnt_p + cnt_g + cnt_m;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 4, 3};
    vector<string> vs = {
            "G", "P", "GP", "GG"
    };
    cout << Solution().garbageCollection(vs, nums);
    return 0;
}
