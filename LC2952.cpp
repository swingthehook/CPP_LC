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
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int minimumAddedCoins(vector<int> &coins, int target) {
        sort(coins.begin(),coins.end());
        int ans = 0;
        int cur = 0;
        int i=0;
        while (cur < target){
            if(i<coins.size() && cur+1 >= coins[i]){    //cur表示当前能取到[0,cur]，如果coins[i]==cur+1，则cur+1直接取coins[i]即可
                cur+=coins[i];                          //则[0,cur+coins[i]]都能取到（[0,cur]++[coins[i]+0,coins[i]+cur]）
                ++i;                                    //如果cur > coins[i]，则可以取到[0,cur+coins[i]]
            }else{
                ans++;                                  //如果coins[i] 比 cur还大，则[cur+1,coins[i]]是取不到的
                cur = cur*2+1;                          //添加硬币cur+1，则可以取到[0,cur-2+1]所有的数
            }                                           //不能添加cur，因为[0,cur]已经可以取到了，应该添加cur+1的硬币，cur+1取这个硬币即可
        }
        return ans;
    }
};




int main() {
    int num = 2;
    vector<int> nums = {100000};
    Solution().minimumAddedCoins(nums,100000);
    return 0;
}
