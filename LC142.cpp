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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast ,*slow;
        fast = slow = head;
        while (1)
        {
            if(!fast)
                return NULL;
            fast=fast->next;
            slow=slow->next;
            if(fast){
                fast=fast->next;
            }else{
                return NULL;
            }
            if(fast==slow)
                break;
        }
        fast=head;
        while (fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
        
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    cout << "sfgddxb"<<endl;
    return 0;
}
