
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> st[len];
        vector<int> ans(len);
        for (int i = 0; i < len; i++)
        {
            while (!st->empty()&&temperatures[i]>temperatures[st->top()]){
                ans[st->top()] = i-st->top();
                st->pop();
            }
            st->push(i);
            
        }
        while (!st->empty())
        {
            ans[st->top()]=0;
            st->pop();
        }
        
        return ans;
    }
};
int main() {

    vector<int> maxHeight = {73,74,75,71,69,72,76,73};
    auto sol = new Solution();
    auto ans = sol->dailyTemperatures(maxHeight);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    




}
