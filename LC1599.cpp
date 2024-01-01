
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int max = -1e9, profit = 0;
        int len = customers.size();
        int waiting = 0;
        int times = 0, maxtimes = -1;
        for (times = 0; times < len;) {
            profit -= runningCost;
            if (customers[times] > 4) {
                profit += boardingCost << 2;
                waiting += customers[times] - 4;
            } else if (waiting + customers[times] >= 4) {
                profit += boardingCost << 2;
                waiting -= (4 - customers[times]);
            } else {
                profit += (waiting + customers[times])*boardingCost;
                waiting = 0;
            }
            times++;
            maxtimes = profit > max ? times : maxtimes;
            max = profit > max ? profit : max;
        }
        while (waiting > 0) {
            times++;
            profit -= runningCost;
            profit += waiting > 4 ? boardingCost << 2 : boardingCost * waiting;
            waiting = waiting > 4 ? waiting - 4 : 0;
            maxtimes = profit > max ? times : maxtimes;
            max = profit > max ? profit : max;
        }
        return max > 0? maxtimes:-1;
    }
};

int main() {

    vector<int> p = {1,0,3};
    auto ans = Solution().minOperationsMaxProfit(p, 61, 55);


    return 0;
}
