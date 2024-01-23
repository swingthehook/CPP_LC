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
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if(!head)
            return head;
        ListNode* p=head;
        while (p->next){
            if(p->next->val == val)
                p->next = p->next->next;
            else
                p=p->next;
        }
        return head;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    auto ans = Solution().alternatingSubarray(nums);
    cout << ans;
    return 0;
}
