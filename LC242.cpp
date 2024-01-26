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
    bool isAnagram(string s, string t) {
        int count[26]={0};
        for(char c:s){
            count[c-'a']++;
        }
        for(char c:t){
            count[c-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if(count[i])
                return false;
        }
        return true;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    cout << "sfgddxb"<<endl;
    return 0;
}
