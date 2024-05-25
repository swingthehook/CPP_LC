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
    bool lemonadeChange(vector<int> &bills) {
        int cnt1 = 0, cnt2 = 0;
        for(int each:bills){
            if(each ==5){
                cnt1++;
            }else if(each == 10){
                cnt1--;
                cnt2++;
            }else{
                if(cnt2>0){
                    cnt2--;
                    cnt1--;
                }
                else{
                    cnt1-=3;
                }
            }
            if(cnt1<0 || cnt2<0)
                return false;
        }
        return true;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    Solution().lemonadeChange(nums);
    return 0;
}
