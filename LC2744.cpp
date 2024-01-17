
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
    int maximumNumberOfStringPairs(vector<string> &words) {
        set<int> st;
        int temp;
        int ans = 0;
        for (string s: words) {
            temp = (1 << (s[0] - 'a')) + (1 << (s[1] - 'a'));
            cout << s << endl;
            cout << temp << endl;
            if (st.find(temp) != st.end())
                ans++;
            else
                st.emplace(temp);
        }
        return ans;
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> dictionary = {"wk", "xf", "ot", "je", "hd", "kw", "fx", "to", "ej"};
    string s2 = "abc";
    auto ans = Solution().maximumNumberOfStringPairs(dictionary);


    return 0;
}
