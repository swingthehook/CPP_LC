//
// Created by 51350 on 2023/12/24.
//
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n=1;
        for(;2*n*(n+1)*(2*n+1)<neededApples;n++)
            ;
        return n*8;
    }
};

//数学计算
