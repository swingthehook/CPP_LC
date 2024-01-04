
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* p=head,q;
        while (p!=NULL){
            while (!stk.empty() && stk.top()->val < p->val) stk.pop();
            if(stk.empty())
                head = p;
            else{
                stk.top()->next=p;
            }
            stk.push(p);
            p=p->next;
        }
        return head;
    }
};

int main() {

    vector<int> p = {1, 0, 3};
    string s1="ecbafedcba";
    string s2="abcdef";
    auto ans = Solution().getMaxRepetitions(s1,4,s2,1);


    return 0;
}
