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
    string clearDigits(string s) {
        deque<pair<char, int>> nums, chars;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (chars.empty()) {
                    nums.push_back(make_pair(s[i], i));
                } else {
                    chars.pop_back();
                }
            } else {
                chars.push_back(make_pair(s[i], i));

            }
        }
        string ans;
        while (!nums.empty() && !chars.empty()) {
            if (nums.front().second < chars.front().second) {
                ans += nums.front().first;
                nums.pop_front();
            } else {
                ans += chars.front().first;
                chars.pop_front();
            }
        }
        while (!nums.empty()) {
            ans += nums.front().first;
            nums.pop_front();
        }
        while (!chars.empty()) {
            ans += chars.front().first;
            chars.pop_front();
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().clearDigits("cb34");
    return 0;
}
