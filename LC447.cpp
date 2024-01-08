
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        for(auto p:points){
            //p为拐点
            unordered_map<int,int> dis;
            int tmp;
            for(auto q:points){
                tmp = (p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
                dis[tmp]++;
            }
            for(auto p:dis){
                ans+= p.second*(p.second-1);
            }
        }
        return ans;
    }
};

int main() {

    vector<int> p = {0,1,2,2,3,0,4,2};
    string s1 = "ecbafedcba";
    string s2 = "abcdef";
    auto ans = Solution().removeElement(p,2);
    for (int i = 0; i < ans; ++i) {
        cout<<p[i]<<' ';
    }

    return 0;
}
