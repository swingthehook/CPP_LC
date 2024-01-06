
#include "bits/stdc++.h"

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p=head;
        while(p->next!=NULL){
            ListNode* tmp=new ListNode(gcd(p->val,p->next->val),p->next);
            p->next=tmp;
            p=tmp->next;
        }
        return head;
    }
};

int main() {

    vector<int> p = {0,1,2,2,3,0,4,2};
    string s1 = "ecbafedcba";
    string s2 = "abcdef";
    auto ans = Solution().removeElement(p,2);
    for (int i = 0; i < ans; ++i) {
        cout<<p[i]<<' ';
    }

    return 0;
}
