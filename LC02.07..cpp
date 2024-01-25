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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int counta = 0, countb = 0;
        ListNode *p = headA;
        while (p) {
            counta++;
            p = p->next;
        }
        p = headB;
        while (p) {
            p = p->next;
            countb++;
        }
        int temp = counta - countb;
        ListNode *pa = headA, *pb = headB;
        if (temp > 0) {
            while (temp--)
                pa = pa->next;
        } else {
            while (temp++)
                pb = pb->next;
        }
        while (pa&&pa!=pb){
            pa=pa->next;
            pb=pb->next;
        }
        return pa;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    auto ans = Solution().alternatingSubarray(nums);
    cout << ans;
    return 0;
}
