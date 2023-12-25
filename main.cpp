
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        if(tomatoSlices > cheeseSlices*4) return ans;
        if (tomatoSlices < cheeseSlices*2) return ans;
        if (tomatoSlices%2 == 1) return ans ;
        ans.push_back((tomatoSlices-2*cheeseSlices)/2);
        ans.push_back((4*cheeseSlices-tomatoSlices)/2);
        return ans;
    }
};

int main() {

    cout<<"fuck you vscode"<<endl;
    return 0;
}
