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
    int maximumSwap(int num) {
        priority_queue<int> pq;
        vector<int> nr;
        int temp = num;
        while (temp != 0) {
            int t = temp % 10;
            pq.push(t);
            nr.push_back(t);
            temp /= 10;
        }
        int i = nr.size() - 1;
        while (i >= 0 && nr[i] == pq.top()) {
            i--;
            pq.pop();
        }
        for (int j = 0; j < i; ++j) {
            if (nr[j] == pq.top()) {
                swap(nr[j], nr[i]);
                break;
            }
        }
        int ans = 0;
        for (int j = nr.size() - 1; j >= 0; --j) {
            ans *= 10;
            ans += nr[j];
        }
        return ans;
    }
};

int main() {
    int num = 2;
    auto ans = Solution().maximumSwap(2736);
    cout << ans;
    return 0;
}
