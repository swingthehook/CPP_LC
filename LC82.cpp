
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *sb = new ListNode(0, head);
        ListNode *p = sb, *q = p->next;
        while (p) {
            if (p->next && p->next->next && p->next->val == p->next->next->val) {
                int val = p->next->val;
                q = p->next->next;
                while (q && q->val == val)
                    q=q->next;
                p->next = q;
            }
            else{
                p = p->next;
            }
        }
        return sb->next;
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
