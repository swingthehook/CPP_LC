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
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0;
        while (i < nums.size() && nums[i] == nums[0]) ++i;
        if(i==nums.size())
            return 1;
        int flag = nums[i]-nums[0];
        int ans=2;
        while (i<nums.size()){
            if(flag>0){
                while (i<nums.size() && nums[i]>=nums[i-1]) ++i;
                if(i<nums.size()){
                    ans++;
                    flag = -flag;
                }
            }else if(flag <0){
                while (i<nums.size() && nums[i]<=nums[i-1]) ++i;
                if(i<nums.size()){
                    ans++;
                    flag = -flag;
                }
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,7,4,9,2,5};
    Solution().wiggleMaxLength(nums);
    return 0;
}
