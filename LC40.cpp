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
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum=0;
    int tar;
    void rec(vector<int>& candidates,int depth,int idx){
        if(sum>=tar)
            return;
        for(int i=idx;i<candidates.size();++i){
            sum+=candidates[i];
            tmp.push_back(candidates[i]);
            if(sum > tar){
                sum -= candidates[i];
                tmp.pop_back();
                return;
            }


            if(sum == tar){
                //tmp.resize(depth+1);
                ans.push_back(tmp);
            }else{
                rec(candidates,depth+1,i+1);
            }
            sum-=candidates[i];
                tmp.pop_back();
            while (i+1<candidates.size() && candidates[i+1] == candidates[i]) ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(),candidates.end());
        rec(candidates,0,0);
        return ans;
    }
};


int main() {
    int num = 2;
    vector<int> nums = {1};
    Solution().combinationSum2(nums,1);
    return 0;
}
