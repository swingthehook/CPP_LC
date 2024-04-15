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
            if(sum > tar){
                sum -= candidates[i];
                return;
            }
            if(tmp.size()>depth){
                tmp[depth] = candidates[i];
            }else{
                tmp.push_back(candidates[i]);
            }
            if(sum == tar){
                tmp.resize(depth+1);
                ans.push_back(tmp);
            }else
                //传入i，保证只搜本数字和之后的数字，不会重复搜索
                rec(candidates,depth+1,i);
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(),candidates.end());
        rec(candidates,0,0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2,3,6,7};
    
    Solution().combinationSum(nums,7);
    return 0;
}
