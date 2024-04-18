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
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2 == 1)
            return {};
        vector<int> ans;
        vector<int> mp(200001);
        std::sort(changed.begin(), changed.end());
        for(int a:changed){
            mp[a]++;
        }
        for(int a:changed){
            if(mp[a] == 0)
                continue;
            else{
                mp[a]--;
                if(mp[a*2]!=0){
                    mp[a*2]--;
                    ans.push_back(a);
                }else if((a&1)==0 &&mp[a/2]!=0){
                    mp[a/2]--;
                    ans.push_back(a/2);
                }else
                    return {};
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {1,3,4,2,6,8};
    Solution().findOriginalArray(nums);
    return 0;
}
