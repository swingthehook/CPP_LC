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

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stk.top();
                stk.pop();
                int a=stk.top();
                stk.pop();
                if(s =="+")
                    stk.push(a+b);
                else if(s == "-")
                    stk.push(a-b);
                else if(s == "*")
                    stk.push(a*b);
                else
                    stk.push(a/b);
            } else
                stk.push(atoi(s.c_str()));
        }
        return stk.top();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
