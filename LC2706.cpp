
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first=1000,second=1000;
        int len=prices.size();
        for (int elem:prices)
        {
            second = elem<first?first:(elem<second?elem:second);
            first = elem < first?elem:first;
        }
        first = money-first-second;
        return first<0?money:first;
    }
};
int main() {
    
    vector<int> p = {20,1,5};
    Solution();

    return 0;
}
