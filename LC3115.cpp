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
    set<int> caled;
    set<int> nt;
    bool isa(int num){
        if(num == 1)
            return false;
        else if(num == 2 ||caled.find(num)!=caled.end())
            return true;
        else if(num%2){
            if(nt.find(num)!=nt.end())
                return false;
            else{
                int sqrtrt = sqrt(num);
                for(int i=2;i<=sqrtrt;++i){
                    if(num%i==0){
                        nt.emplace(num);
                        return false;
                    }
                }
                caled.emplace(num);
                return true;
            }
        }
        return false;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int minidx=-1,maxidx=-1;
        for(int i=0;i<nums.size();++i){
            if(isa(nums[i])){
                minidx = minidx==-1?i:minidx;
                maxidx = i;
            }
        }
        return maxidx-minidx;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution();
    return 0;
}
