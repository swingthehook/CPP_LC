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
    vector<vector<string>> ans;
    vector<string> tmp;
    bool is_(string s){
        int i=0;
        int j=s.size()-1;
        while (i<=j){
            if(s[i] == s[j]){
                ++i;
                --j;
            }else
                return false;
        }
        return true;
    }
    void rec(string s,int start){
        if(start >= s.size())
            ans.push_back(tmp);
        int i=start;
        for (; i < s.size(); ++i) {
            string sub = s.substr(start,i-start+1);
            if(is_(sub)){
                tmp.push_back(sub);
                rec(s,i+1);
                tmp.pop_back();
            }else
                continue;
        }
    }
    vector<vector<string>> partition(string s) {
        rec(s,0);
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    string s="aab";
    Solution().partition(s);
    return 0;
}
