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
    string maximumOddBinaryNumber(string s) {
        //计数变量
        int cnt1=0;
        string ans;
        for(auto c:s){
            if(c =='1')
                cnt1++;
        }
        int cnt0=s.size()-cnt1;
        while (--cnt1)
            ans+='1';
        while (cnt0--)
            ans+='0';
        ans+='1';
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution().maximumOddBinaryNumber("1011");
    return 0;
}
