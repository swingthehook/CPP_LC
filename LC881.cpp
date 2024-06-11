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
    int numRescueBoats(vector<int> &people, int limit) {
        std::sort(people.begin(), people.end());
        int len = people.size();
        int i = 0, j = len - 1;
        int ans = 0;
        if (len > 1 && people[j] + people[j - 1] <= limit)
            return len / 2 + len % 2;
        while (i <= j) {
            if (i < j && people[i] + people[j] <= limit) {
                ++i;
                --j;
            } else {
                --j;
            }
            ++ans;

        }
        return ans;
    }
};

{
1,2,4,4,5,7}

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution();
    return 0;
}
