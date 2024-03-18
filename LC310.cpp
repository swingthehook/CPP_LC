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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> n_tb(n);
        for (auto edge: edges) {
            n_tb[edge[0]].push_back(edge[1]);
            n_tb[edge[1]].push_back(edge[0]);
        }
        int start;
        for (int i = 0; i < n; ++i) {
            if (n_tb[i].size() == 1) {
                start = i;
                break;
            }
        }
        queue<pair<int, int>> q;
        int max;
        q.push(make_pair(start, 0));
        vector<bool> visit(n, false);
        vector<int> parent(n);
        int last;
        while (!q.empty()) {
            auto tmp = q.front();
            visit[tmp.first] = true;
            q.pop();
            for (auto i: n_tb[tmp.first])
                if (!visit[i]){
                    q.push(make_pair(i, tmp.second + 1));
                    parent[i] = tmp.first;
                }
            max = tmp.second;
            last = tmp.first;
        }
        start = last;
        q.push(make_pair(start,0));
        visit.clear();parent.clear();
        visit.resize(n);parent.resize(n);
        while (!q.empty()) {
            auto tmp = q.front();
            visit[tmp.first] = true;
            q.pop();
            for (auto i: n_tb[tmp.first])
                if (!visit[i]){
                    q.push(make_pair(i, tmp.second + 1));
                    parent[i] = tmp.first;
                }
            max = tmp.second;
            last = tmp.first;
        }
        vector<int> path;
        parent[start] = -1;
        while (last!= -1){
            path.push_back(last);
            last = parent[last];
        }
        if(max%2)
            return {path[max/2],path[max/2+1]};
        else
            return {path[max/2]};
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    vector<vector<int>> edges = {
            {3, 0},
            {3, 2},
            {1, 3},
            {3, 4},
            {5, 4}
    };
    Solution().findMinHeightTrees(6, edges);
    return 0;
}
