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
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1;
        int len = plants.size();
        int tmpa = capacityA, tmpb = capacityB;
        int ans = 0;
        while (i < j) {
            if (tmpa >= plants[i]) {
                tmpa -= plants[i];
                ++i;
            } else if (capacityA >= plants[i]) {
                ans++;
                tmpa = capacityA - plants[i];
                ++i;
            }
            if (tmpb >= plants[j]) {
                tmpb -= plants[j];
                --j;
            } else if (capacityB >= plants[j]) {
                ans++;
                tmpb = capacityB-plants[j];
                --j;
            }
        }
        cout<<tmpa<<endl<<tmpb<<endl;
        if (i == j) {
            if (tmpa < plants[i] && tmpb < plants[i])
                ans++;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {6,6,6,6,6};
    Solution().minimumRefill(nums, 6, 6);
    return 0;
}
