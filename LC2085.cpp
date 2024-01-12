
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
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans=0;
        unordered_map<string,int> m1,m2;
        for(string s:words1){
            m1[s]++;
        }
        for(string s:words2){
            m2[s]++;
        }
        for(auto ite = m1.begin();ite!=m1.end();ite++){
            if(ite->second ==1 && m2[ite->first]==1) ans++;
        }
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
