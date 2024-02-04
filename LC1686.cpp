#include <bits/stdc++.h>

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
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
        multimap<int, pair<int, int>, greater<int>> mp;
        for (int i = 0; i < aliceValues.size(); ++i) {
            mp.emplace(aliceValues[i] + bobValues[i], make_pair(aliceValues[i], bobValues[i]));
        }
        int turn = 0, asum = 0, bsum = 0;
        for (auto ite = mp.begin(); ite != mp.end(); ite++) {
            if (!turn) {
                asum += ite->second.first;
            } else {
                bsum += ite->second.second;
            }
            turn=1-turn;
        }
        if(asum>bsum) return 1;
        else if(asum==bsum) return 0;
        else return -1;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
