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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        vector<long long> sum,count;
        while (!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp.first->left)
                q.push(make_pair(tmp.first->left,tmp.second+1));
            if(tmp.first->right)
                q.push(make_pair(tmp.first->right,tmp.second+1));
            if(sum.size() < tmp.second+1){
                sum.push_back(tmp.first->val);
                count.push_back(1);
            } else{
                sum[tmp.second] += tmp.first->val;
                count[tmp.second]++;
            }
        }
        for (int i = 0; i < sum.size(); ++i) {
            ans.push_back(double(sum[i])/count[i]);
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
