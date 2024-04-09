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
    int minOperations(vector<int> &nums) {
        int len = nums.size();
        int ans=1e9;
        std::sort(nums.begin(), nums.end());
        //unique只能去除相邻的重复元素，要先sort，返回的是去过重的序列的尾后iterator
        auto re = std::unique(nums.begin(), nums.end());
        nums.resize(re-nums.begin());
        int i=0,j=0;
        while (j<nums.size()){
            while (j<nums.size()&&nums[j]<=nums[i]+len-1)
                ++j;
            ans = min(ans,len-(j-i));
            ++i;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {41, 33, 29, 33, 35, 26, 47, 24, 18, 28};
    cout<<Solution().minOperations(nums);
    return 0;
}
