
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
    int addMinimum(string word) {
        int ans = 0;
        int len = word.size();
        ans += word[0]-'a';
        for (int i = 0; i < len-1; ++i) {
            ans+=(word[i+1]-word[i]+2)%3;
        }
        ans+=2-(word[len-1]-'a');
        return ans;
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    string s2 = "abc";
    auto ans = Solution().addMinimum(s2);


    return 0;
}
