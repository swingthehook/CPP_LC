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
    bool isHappy(int n) {
        set<int> history;
        while (n!=1){
            int temp=n;
            n=0;
            while (temp){
                n+=(temp%10)*(temp%10);
                temp/=10;
            }
            if(history.find(n)!= history.end())
                return false;
            else
                history.insert(n);
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
