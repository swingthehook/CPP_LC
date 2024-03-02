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

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        vector<vector<int>> tb(n);
        vector<bool> visit(n, false);
        vector<bool> isrestricted(n, false);
        for (int i = 0; i < restricted.size(); ++i) {
            isrestricted[restricted[i]]=true;
        }
        for (auto i: edges) {
            tb[i[0]].push_back(i[1]);
            tb[i[1]].push_back(i[0]);
        }
        int ans = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            visit[tmp] = true;
            if (isrestricted[tmp])
                continue;
            ans++;
            for (auto i: tb[tmp]) {
                if (!visit[i])
                    q.push(i);
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
