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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int i=0,j=0;
        int count = 1;
        int direction = 1;
        int circle=0;
        while (circle<n/2){
            ans[i][j]=count;
            ++count;
            if(direction == 1){
                if(j<(n-circle-1)){
                    j++;
                }
                else{
                    i++;
                    direction=2;
                }
            } else if(direction == 2){
                if(i<n-circle-1){
                    i++;
                } else{
                    j--;
                    direction=3;
                }
            }else if(direction==3) {
                if (j > (circle)) {
                    j--;
                } else {
                    i--;
                    direction = 4;
                    if(i< circle+1)
                        break;
                }
            }
            else{
                if(i>circle+1){
                    i--;
                } else{
                    j++;
                    circle++;
                    direction=1;
                }
            }
        }
        if(n%2){
            ans[n/2][n/2]=n*n;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int num=2;
    auto ans = Solution().generateMatrix(num);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
