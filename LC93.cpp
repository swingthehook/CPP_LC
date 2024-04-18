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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int len=s.size();
        for (int i = 0; i < 3; ++i) {
            if(len-(i+1)>9 || len-(i+1)<3|| (i>0 && s[0] =='0') || stoi(s.substr(0,i+1))>255)
                continue;
            for (int j = 0; j < 3; ++j) {
                if(len-(i+1)-(j+1)>6|| len-(i+1)-(j+1)<2 || (j>0&&s[i+1]=='0') || stoi(s.substr(i+1,j+1))>255)
                    continue;
                for (int k =0; k < 3; ++k) {
                    if(len-(i+1)-(j+1)-(k+1)>3|| len-(i+1)-(j+1)-(k+1)<1 || (k>0&&s[i+1+j+1]=='0') || stoi(s.substr(i+1+j+1,k+1))>255)
                        continue;
                    if(s[i+j+k+3]=='0' && len-i-1-j-1-k-1>1 || i+j+k+3>len-1 || stoi(s.substr(i+j+k+3,len-i-1-j-1-k-1))>255)
                        continue;
                    string tmp;
                    tmp=tmp+s.substr(0,i+1)+"."+s.substr(i+1,j+1)+"."+s.substr(i+1+j+1,k+1)+"."+s.substr(i+j+k+3,len-i-1-j-1-k-1);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};

    Solution().restoreIpAddresses("1111");
    return 0;
}
