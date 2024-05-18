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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int acc = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            acc += gas[i] - cost[i];
            if (acc < 0) {
                start = (i + 1)%gas.size();
                acc = 0;
            }
        }
        if(sum>=0)
            return start;
        else return -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,2,3,4,5};
    vector<int> nus = {3,4,5,1,2};
    Solution().canCompleteCircuit(nums,nus);
    return 0;
}
