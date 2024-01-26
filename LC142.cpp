#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    起点到入口距离为x，入口到快慢相遇为y，相遇点绕回入口为z
    fast = x+y+n(y+z)
    slow = x+y           ->   n(y+z) = x+y  ->  x = (n-1)y+nz=(n-1)(y+z)+z
    fast = 2*slow
    此时，从起点向入口出发，距离为x，从相遇点向入口出发，距离为z，两个指针同步前进
    从相遇点出发的指针可能会绕圈[(n-1)圈]
*/
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
