
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
    ListNode *reverse(ListNode *head) {
        ListNode *newhead = NULL, *tmp;
        while (head != NULL) {
            tmp = head;
            head = head->next;
            tmp->next = newhead;
            newhead = tmp;
        }
        return newhead;
    }

    ListNode *removeNodes(ListNode *head) {
        head = reverse(head);
        ListNode *tmp = head;
        while (tmp && tmp->next) {
            while (tmp->next&& tmp->val > tmp->next->val) {
                tmp->next = tmp->next->next;
            }
            tmp = tmp->next;

        }
        return reverse(head);
    }
};

int main() {

    vector<int> p = {1, 0, 3};
    string s1 = "ecbafedcba";
    string s2 = "abcdef";
    auto ans = Solution().getMaxRepetitions(s1, 4, s2, 1);


    return 0;
}
