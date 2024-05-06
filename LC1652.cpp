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
    vector<int> decrypt(vector<int>& code, int k) {
        int sum=0;
        if(k == 0)
            return vector<int> (code.size());
        int i,j;
        if(k>0){
            i=1;
            j=i;
            for (int l = 0; l < k; ++l) {
                sum+=code[j];
                ++j;
            }
            --j;
        }else{
            j=code.size()-1;
            i=j;
            for (int l = 0; l < -k; ++l) {
                sum+=code[i];
                --i;
            }
            ++i;
        }
        vector<int> ans(code.size());
        for (int l = 0; l < code.size(); ++l) {
            ans[l]=sum;
            sum-=code[i];
            ++i;
            i%=code.size();
            ++j;
            j%=code.size();
            sum+=code[j];
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2,4,9,3};
    Solution().decrypt(nums,-2);
    return 0;
}
