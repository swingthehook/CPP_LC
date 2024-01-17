
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head,*q;
        while(p!=NULL){
            while (p->next!=NULL && p->next->val == p->val){
                q=p->next;
                p->next=q->next;
            }
            p=p->next;
        }
        return head;
    }
};

int main() {

    vector<int> p = {0, 1, 2, 2, 3, 0, 4, 2};
    string s1 = "leetscode";
    vector<string> dictionary = {"wk", "xf", "ot", "je", "hd", "kw", "fx", "to", "ej"};
    string s2 = "abc";
    auto ans = Solution().maximumNumberOfStringPairs(dictionary);


    return 0;
}
