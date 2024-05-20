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
    int longestAwesome(string s) {
        int sz=s.size();
        unordered_map<int,int> prefix={{0,-1}};
        int ans=0;
        int sequence=0;
        for (int i = 0; i < sz; ++i) {
            sequence^= (1<<(s[i]-'0'));
            if (prefix.find(sequence)!=prefix.end()){
                ans = max(ans,i-prefix[sequence]);
            }else{
                prefix[sequence] = i;
            }
            for (int j = 0; j < 10; ++j) {
                sequence^=1<<j;
                if(prefix.find(sequence)!=prefix.end()){
                    ans = max(ans,i-prefix[sequence]);
                }
                sequence^=1<<j;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().longestAwesome("9498331");
    return 0;
}
