
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mask(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mask[i] += matrix[i][j] << (n - j - 1);
            }
        }
        int ans = 0;
        int cur = 0;
        int max = 1 << n;
        int count;
        while (++cur<max){
            if (__builtin_popcount(cur)!=numSelect){
                continue;
            }
            count=0;
            for (int i = 0; i < m; ++i) {
                if((mask[i]&cur) == mask[i])
                    count++;
            }
            ans = ans>count?ans:count;
        }
        return ans;
    }
};


int main() {

    vector<int> p = {1, 0, 3};
    string s1="ecbafedcba";
    string s2="abcdef";
    auto ans = Solution().getMaxRepetitions(s1,4,s2,1);


    return 0;
}
