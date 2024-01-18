
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
    //数学计算
    long long minimumRemoval(vector<int> &beans) {
        sort(beans.begin(), beans.end());
        long long total = 0;
        for (int it: beans) {
            total += it;
        }
        long long ans = total;
        int n = beans.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans,total - (long long )beans[i]*(n-i));
        }
        return ans;

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
