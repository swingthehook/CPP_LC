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
    bool isValidSerialization(string preorder) {
        if (preorder.size() > 1 && preorder.front() == '#')
            return false;
        int slot = 1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (slot == 0)
                return false;
            if (preorder[i] == '#') {
                --slot;

            } else if (preorder[i] == ',');
            else {

                while (preorder[i] >= '0' && preorder[i] <= '9')
                    ++i;
                ++slot;
            }
        }
        return slot == 0;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    string s = {9, 3, 4, '#', '#', 1, '#', '#', 2, '#', 6, '#', '#'};
    Solution().isValidSerialization(s);
    return 0;
}
