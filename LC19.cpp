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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p,*q,sb(0,head);
        p=&sb;
        q=head;
        while (n--)
            q=q->next;
        while (q){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return sb.next;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    auto ans = Solution().alternatingSubarray(nums);
    cout << ans;
    return 0;
}
