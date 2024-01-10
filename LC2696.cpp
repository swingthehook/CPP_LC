
#include "bits/stdc++.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c: s) {
            if (!stk.empty() && (c == 'B' && stk.top() == 'A' || c == 'D' && stk.top() == 'C')) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    string s2 = "abcdef";
    auto ans = Solution().minExtraChar(s1, dictionary);


    return 0;
}
