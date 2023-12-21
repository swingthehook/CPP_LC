
#include "bits/stdc++.h"
using namespace std;

int bh(int n){
    int a[4];
    for (int i = 0; i < 4; ++i) {
        a[i]=n%10;
        n/=10;
    }
    sort(a,a+4);
    int bigger=0,smaller=0;
    for (int i = 0; i < 4; ++i) {
        smaller*=10;
        smaller+=a[i];
        bigger*=10;
        bigger+=a[3-i];
    }
    return bigger - smaller;

}

int main() {

    int n;
    cin>>n;
    cout<<n;
    //撒个娇哈喽健康是福亮机卡说法
    return 0;




}
