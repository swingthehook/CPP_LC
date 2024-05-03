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
    vector<bool> visit;
    vector<int> tmp;
    vector<vector<int>> ans;
    void rec(vector<int>& nums,int depth){
        if(depth == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(i>0 && nums[i] == nums[i-1] && !visit[i-1])
                continue;
            if(!visit[i]){
                visit[i]=true;
                tmp.push_back(nums[i]);
                rec(nums,depth+1);
                tmp.pop_back();
                visit[i]=false;
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        visit.resize(nums.size());
        rec(nums,0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,1,2};
    Solution().permuteUnique(nums);
    return 0;
}
