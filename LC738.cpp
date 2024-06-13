#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        /*一旦一个位置减一，后面所有位都可以为9
         * 找最长的高位相同的递增序列
         * 从递减的地方开始，减一，后面都置为9即可
         * */
        string num = to_string(n);
        int idx = 1;
        while (idx<num.size() && num[idx] >=num[idx-1])
            ++idx;
        if(idx<num.size()){
            while (idx>0 && num[idx]<num[idx-1]){
                num[idx-1]-=1;
                --idx;
            }
            for(idx++;idx<num.size();++idx)
                num[idx]='9';
        }
        return stoi(num);
    }
};


int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
