
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1=0,sum2=0;
        int len=player1.size();
        for (int i = 0; i < len; i++)
        {
            sum1+= (i>0&&player1[i-1]==10||i>1 && player1[i-2]==10)?player1[i]<<1:player1[i];
            sum2+= (i>0&&player2[i-1]==10||i>1 &&player2[i-2]==10)?player2[i]<<1:player2[i];
        }
        return sum1>sum2?1:(sum1<sum2?2:0);
        
    }
};

int main() {

    Solution solution = Solution();
    vector<int> p1 = {10,2,2,3};
    vector<int> p2 = {3,8,4,5};
    cout<<solution.isWinner(p1,p2)<<endl;;
    return 0;
}
