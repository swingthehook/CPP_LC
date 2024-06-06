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
    long long minimumSteps(string s) {
        long long ans = 0;
        int ptr0 = 0, ptr1 = 0;
        int len = s.size();
        if (s[0] == '1') {
            while (ptr1 < len && s[ptr1] == '1') ++ptr1;
            if(ptr1==len) return 0;
            ans += (ptr1 - ptr0);
        } else {
            while (ptr0 < len && s[ptr0] == '0') ++ptr0;
            ptr1 = ptr0;
            --ptr0;
        }
        ++ptr1;
        while (ptr1<len){
            if(s[ptr1] == '0'){
                ans+=(ptr1-ptr0-1);
                ptr0++;
            }
            ptr1++;
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().minimumSteps("100");
    return 0;
}
