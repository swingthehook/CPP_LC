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
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        vector<vector<int>> ans;
        set<int> lose0, lose1, other;
        for (auto &each: matches) {
            if (lose1.find(each[0]) == lose1.end() && other.find(each[0]) == other.end()) {
                lose0.emplace(each[0]);
            }
            if (lose0.find(each[1]) != lose0.end()) {
                lose0.erase(each[1]);
                lose1.emplace(each[1]);
            } else if (other.find(each[1]) == other.end()) {

                if (lose1.find(each[1]) == lose1.end()) {
                    lose1.emplace(each[1]);
                } else {
                    lose1.erase(each[1]);
                    other.emplace(each[1]);
                }
            }
        }
        ans.push_back(vector<int>(lose0.begin(), lose0.end()));
        ans.push_back(vector<int>(lose1.begin(), lose1.end()));
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
