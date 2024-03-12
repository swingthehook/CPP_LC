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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode* ,int>> q;
        q.push(make_pair(root,0));
        while (!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp.first->left)
                q.push(make_pair(tmp.first->left,tmp.second+1));
            if(tmp.first->right)
                q.push(make_pair(tmp.first->right,tmp.second+1));
            if(q.front().second == tmp.second+1 || q.empty())
                ans.push_back(tmp.first->val);
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution().findKOr(nums,4);
    return 0;
}
