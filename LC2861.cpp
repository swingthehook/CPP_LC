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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=-1;
        for (int i = 0; i < composition.size(); i++)
        {
            int spend=0;
            int count=0;
            while (spend<budget)
            {
                for (int j = 0; j < 3; j++)
                {
                    spend += (count - stock[i]>0? count-stock[i]:0)*cost[i];
                }
                count++;
                
            }
            ans = max(ans,count);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    cout << "sfgddxb"<<endl;
    return 0;
}
