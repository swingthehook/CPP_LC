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
    vector<int> tmp;
    vector<vector<int>> ans;

    void rec(int start, int max, int index, int target_cnt) {
        if (index == target_cnt){
            ans.push_back(tmp);
            return;
        }

        for (int i = start; i<=max-(target_cnt-index)+1 ; ++i) {
            tmp[index] = i;
            rec(i+1,max,index+1,target_cnt);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        tmp.resize(k);
        rec(1, n, 0, k);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().combine(4,2);
    return 0;
}
