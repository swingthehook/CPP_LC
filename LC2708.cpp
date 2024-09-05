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
    long long maxStrength(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        std::sort(nums.begin(), nums.end());
        int negtive_r = 0;
        while (negtive_r < nums.size() && nums[negtive_r] < 0) ++negtive_r;
        int zero_r = negtive_r;
        while (zero_r < nums.size() && nums[zero_r] == 0) ++zero_r;
        int positive_r=nums.size();
        long long ans=0;
        if(negtive_r>1){
            ans=1;
            for (int i = 0; i < negtive_r / 2 * 2; ++i) {
                ans*=nums[i];
            }
        }
        if(positive_r-zero_r>0){
            ans = ans==0?1:ans;
            for(int i=zero_r;i<positive_r;++i)
                ans*=nums[i];
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {-4, -3};
    Solution().maxStrength(nums);
    return 0;
}
