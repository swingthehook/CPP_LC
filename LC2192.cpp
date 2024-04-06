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
    //反向建图，每个节点dfs
    vector<bool> visit;
    vector<vector<int>> tb;
    vector<vector<int>> ans;
    void dfs(int root,int cur){
        for(auto next:tb[cur]){
            if(!visit[next]){
                visit[next]= true;
                ans[root].emplace_back(next);
                dfs(root,next);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        visit.resize(n);
        tb.resize(n);
        ans.resize(n);
        for(auto edge:edges){
            tb[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            visit.assign(n, false);
            dfs(i,i);
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> edges = {{0, 3},
                                 {0, 4},
                                 {1, 3},
                                 {2, 4},
                                 {2, 7},
                                 {3, 5},
                                 {3, 6},
                                 {3, 7},
                                 {4, 6}};
    Solution().getAncestors(8, edges);
    return 0;
}
