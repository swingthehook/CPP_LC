
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int p1 = 0, p2 = 0;
        int len1 = s1.size(), len2 = s2.size();
        int c1 = 0, c2 = 0;
        while (c1<n1) {
            if (s1[p1] == s2[p2]) ++p2;
            ++p1;
            c1 = p1 == len1 ? c1 + 1 : c1;
            c2 = p2 == len2 ? c2 + 1 : c2;
            p1 %= len1;
            p2 %= len2;
            if(!(p1||p2)) break;
        }
        return floor((double)((long long)n1*c2)/((long long )c1*n2));
    }
};

int main() {

    vector<int> p = {1, 0, 3};
    string s1="ecbafedcba";
    string s2="abcdef";
    auto ans = Solution().getMaxRepetitions(s1,4,s2,1);


    return 0;
}
