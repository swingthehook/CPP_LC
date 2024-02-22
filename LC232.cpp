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

class MyQueue {
public:
    stack<int> *stkin, *stkout;

    MyQueue() {
        stkin = new stack<int>;
        stkout = new stack<int>;
    }

    void push(int x) {
        stkin->push(x);
    }

    int pop() {
        if (stkout->empty()) {
            while (!stkin->empty()) {
                stkout->push(stkin->top());
                stkin->pop();
            }
        }
        int tmp = stkout->top();
        stkout->pop();
        return tmp;
    }

    int peek() {
        int tmp = pop();
        stkout->push(tmp);
        return tmp;
    }

    bool empty() {
        return stkin->empty() && stkout->empty();
    }
};

int main() {
    int num = 2;
    vector<int> nums = {2, 3, 4, 3, 4};
    Solution().canMeasureWater(3, 5, 4);
    return 0;
}
