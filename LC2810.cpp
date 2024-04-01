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
    string finalString(string s) {
        deque<char> dq;
        bool reverse= false;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='i')
                reverse=!reverse;
            else if(reverse)
                dq.push_front(s[i]);
            else
                dq.push_back(s[i]);
        }
        if(!reverse)
            return string(dq.begin(),dq.end());
        else
            return string(dq.rbegin(),dq.rend());
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    string str = "string";
    Solution().finalString(str);
    return 0;
}
