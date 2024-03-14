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
        //原地操作原字符串
        int left=0,right=s.size()-1;
        while (s[right]!='1')
            right--;
        swap(s[right],s[s.size()-1]);
        right--;
        while (left<right){
            while (s[right] == '0' && left<right)
                --right;
            while (s[left] == '1' && left<right)
                ++left;
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    Solution().maximumOddBinaryNumber("1011");
    return 0;
}
