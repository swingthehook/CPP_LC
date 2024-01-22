
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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(string s : words){
            int i=0,j=0;
            int len = s.size();
            while (i<len && s[i] == separator)
            {
                i++;
            }
            j=i;
            while (j<len)
            {
                while (j<len && s[j]!=separator)
                {   
                    j++;
                }
                ans.push_back(s.substr(i,j-i));
                i=j;
                while (i<len && s[i] == separator)
                {
                    i++;
                }
                j=i;
            }
        }
        return ans;
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> words = {"one.two.three","four.five","six"};
    char separator='.';
    string s2 = "abc";
    Solution().splitWordsBySeparator(words,separator);
    return 0;
}
