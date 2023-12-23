
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int len =piles.size();
        priority_queue<int> pq;
        for (int i = 0; i < len; i++)
        {
            pq.push(piles[i]);
        }
        int temp;
        for (int i = 0; i < k; i++)
        {
            temp = pq.top();
            temp = temp - temp/2;
            pq.pop();
            pq.push(temp);
        }
        temp =0;
        while (!pq.empty())
        {
            temp += pq.top();
            pq.pop();
        }
        return temp;
        

    }
};

int main() {

    return 0;
}
