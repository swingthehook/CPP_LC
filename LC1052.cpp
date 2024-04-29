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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int angry=0;
        int mx=0;
        int i=0,j=0;
        while (j< minutes && j<customers.size()){
            if(grumpy[j]){
                angry+=customers[j];
            }
            else
                ans+=customers[j];
            ++j;
        }
        mx = angry;
        while (j<customers.size()){
            if(grumpy[i]){
                angry-=customers[i];
            }
            ++i;
            if(grumpy[j])
                angry+=customers[j];
            else
                ans+=customers[j];
            ++j;
            mx = max(mx,angry);
        }
        return ans+mx;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution().maxSatisfied(vector<int>()={3,7},vector<int>()={0,0},2);
    return 0;
}
