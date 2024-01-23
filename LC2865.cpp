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
    /*两遍单调栈，从前到后一遍，找升序和，从后往前一遍，找降序和
     * 结合两个遍历序列，找到最大的山峰和
     * 过程中用单调栈寻找前缀和和后缀和         */
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        int len = maxHeights.size();
        vector<long long> presum(len), sufsum(len);
        stack<int> pre, suf;
        for (int i = 0; i < len; ++i) {
            while (!pre.empty() && maxHeights[i] < maxHeights[pre.top()])
                pre.pop();
            if (pre.empty()) {
                presum[i] = (long long) (i + 1) * maxHeights[i];
            } else {
                presum[i] = presum[pre.top()] + (long long) (i - pre.top()) * maxHeights[i];
            }
            pre.push(i);
        }
        for (int i = len - 1; i >= 0; --i) {
            while (!suf.empty() && maxHeights[i]<maxHeights[suf.top()]){
                suf.pop();
            }
            if(suf.empty()){
                sufsum[i] = (long long)(len-i)*maxHeights[i];
            } else{
                sufsum[i] = sufsum[suf.top()] + (long long)(suf.top()-i)*maxHeights[i];
            }
            suf.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = max(ans,(presum[i]+sufsum[i] - maxHeights[i]));
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    auto ans = Solution().alternatingSubarray(nums);
    cout << ans;
    return 0;
}
