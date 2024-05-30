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
    int maximumLength(string s) {
        int len = s.size();
        vector<vector<int>> cnt(26);
        for (int i = 0; i < len; ++i) {
            int tmp = 1;
            while (i + 1 < len && s[i + 1] == s[i]){
                ++i;
                ++tmp;
            }
            cnt[s[i] - 'a'].push_back(tmp);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i].size()) {
                std::sort(cnt[i].begin(), cnt[i].end(), greater<int>());
                int sz = cnt[i].size();
                ans = max(ans, cnt[i][0] - 2);
                if (sz >= 2) {
                    if (cnt[i][0] > cnt[i][1])
                        ans = max(ans, cnt[i][1]);
                    else
                        ans = max(ans, cnt[i][0] - 1);
                }
                if(sz>=3){
                    ans = max(ans,cnt[i][2]);
                }
            }
        }
        return ans==0?-1:ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().maximumLength("acc");
    return 0;
}
