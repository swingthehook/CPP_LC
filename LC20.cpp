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
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(c == '(' || c == '[' || c == '{')
                stk.push(c);
            else{
                if(stk.empty())
                    return false;
                char c1 = stk.top();
                if(c1 == '(' && c == ')' || c1 == '[' && c == ']' || c1 == '{' && c=='}')
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
