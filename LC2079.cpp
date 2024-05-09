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
    int wateringPlants(vector<int> &plants, int capacity) {
        int ans = 0;
        int tmp = capacity;
        for (int i = 0; i < plants.size(); ) {

            if (tmp < plants[i]) {
                ans += i  << 1;
                tmp = capacity;
            } else{
                tmp-=plants[i];
                ++i;
            }
        }
        ans+= plants.size();
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2,2,3,3};
    Solution().wateringPlants(nums,5);
    return 0;
}
