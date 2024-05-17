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
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        map<int, int> mp;
        for (int i = 0; i < difficulty.size(); ++i) {
            mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]);
        }
        std::sort(worker.begin(), worker.end());
        auto ite1 = mp.begin();
        auto ite2 = ++mp.begin();
        int ans = 0;
        int mx=-1;
        for (int i = 0; i < worker.size(); ++i) {
            while (ite2 != mp.end() && worker[i] >= ite2->first) {
                mx= max(mx,ite1->second);
                ++ite1;
                ++ite2;
            }
            if(worker[i]>=ite1->first){
                mx = max(mx,ite1->second);
                ans+=mx;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums1 = {68,35,52,47,86};
    vector<int> nums2 = {67,17,1,81,3};
    vector<int> nums3 = {92,10,85,84,82};
    Solution().maxProfitAssignment(nums1,nums2,nums3);
    return 0;
}
