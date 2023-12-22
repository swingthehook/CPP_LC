
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int len = maxHeights.size();
        stack<int> pre,suf;
        long long presum[len],sufsum[len];
        for (int i = 0; i < len; ++i) {
            while(!pre.empty() && maxHeights[i]<maxHeights[pre.top()]){
                pre.pop();
            }
            if (pre.empty()){
                presum[i] = (long long )(i+1)*maxHeights[i];
            } else{
                presum[i] = presum[pre.top()] + (long long )(i-pre.top())*maxHeights[i];
            }
            pre.push(i);
        }
        for (int i = len-1; i >=0 ; --i) {
            while (!suf.empty() && maxHeights[i]<maxHeights[suf.top()]){
                suf.pop();
            }
            if(suf.empty()){
                sufsum[i] = (long long )(len-i)*maxHeights[i];
            }
            else{
                sufsum[i] = sufsum[suf.top()] + (long long )(suf.top() - i)*maxHeights[i];
            }
            suf.push(i);
        }
        long long ans=0,temp;

        for (int i = 0; i < len; ++i) {
            temp = presum[i]+sufsum[i] - maxHeights[i];
            ans = ans>temp?ans:temp;
        }
        return ans;
    }
};

int main() {

    vector<int> maxHeight = {3,5,3,5,1,5,4,4,4};
    auto sol = new Solution();
    cout<<sol->maximumSumOfHeights(maxHeight)<<endl;





}
