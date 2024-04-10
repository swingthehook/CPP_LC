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
    string maximumBinaryString(string binary) {
        int len = binary.size(), i = 0, j = 0;
        while (i < len && binary[i] != '0') ++i;
        j=i+1;
        while (j < len) {
            while (i < len && binary[i] != '0') ++i;
            while (j < len && binary[j] != '0') ++j;
            if(j<len){
                binary[i++]='1';
                binary[i] = '0';
                if(j>i)
                    binary[j] ='1';
                else
                    ++j;
            }
        }
        return binary;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    string str="000110";
    Solution().maximumBinaryString(str);
    return 0;
}
