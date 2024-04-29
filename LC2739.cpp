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
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank > 0) {
            if (mainTank >= 5) {
                int tmp = mainTank / 5;

                if (tmp < additionalTank) {
                    ans += tmp * 5;
                    mainTank -= tmp << 2;
                    additionalTank -= tmp;
                } else {
                    ans += tmp * 5;
                    mainTank -= 5 * tmp;
                    mainTank += additionalTank;
                    additionalTank = 0;
                }
            } else {
                ans += mainTank;
                mainTank = 0;
            }
        }
        return ans * 10;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().distanceTraveled(5, 10);
    return 0;
}
