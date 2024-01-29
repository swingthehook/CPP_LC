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
    long long mhash(int a, int b) {
        return ((long long) a << 32) | b;
    }

    unordered_map<long long, int> record;

    bool judge(int jug1, int jug2, int target, int a, int b) {
        record[mhash(a, b)]++;
        if (a == target || b == target) {
            return true;
        } else if (record[mhash(a, b)]==2) {
            return false;
        } else {

            return judge(jug1, jug2, target, jug1, b) || judge(jug1, jug2, target, a, jug2) ||
                   judge(jug1, jug2, target, 0, b) || judge(jug1, jug2, target, a, 0) ||
                   judge(jug1, jug2, target, a + b > jug1 ? jug1 : a + b, a + b > jug1 ? a + b - jug1 : 0) ||
                   judge(jug1, jug2, target, a + b > jug2 ? a + b - jug2 : 0, a + b > jug2 ? jug2 : a + b);
        }
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return judge(jug1Capacity, jug2Capacity, targetCapacity, 0, 0);
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
