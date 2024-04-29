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
    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0] || v1[0] == v2[0] && v1[1] < v2[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(people.size());
        for (auto vec: people) {
            int cnt = 0;
            int i = 0;
            if(vec[1] == 0){
                while (ans[i].size()!=0 && ans[i][0]<vec[0]) ++i;
                ans[i] = vec;
            }else{
                while (cnt<vec[1]){
                    if(ans[i].size() == 0 || ans[i][0]>=vec[0]) ++cnt;
                    ++i;
                }
                while (ans[i].size()) ++i;
                ans[i] = vec;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> pp = {
            {7, 0},
            {4, 4},
            {7, 1},
            {5, 0},
            {6, 1},
            {5, 2}
    };
    Solution().reconstructQueue(pp);
    return 0;
}
