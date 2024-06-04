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
    vector<int> distributeCandies(int candies, int num_people) {
        int total = num_people * (num_people + 1) / 2;
        int round = 0;
        while (1) {
            int tmp = candies - total - round * num_people*num_people;
            if (tmp > 0) {
                round++;
                candies = tmp;
            } else
                break;
        }
        vector<int> ans(num_people);
        for (int i = 0; i < num_people; ++i) {
            ans[i] = round * (i + 1) + round * (round - 1) / 2 * num_people;
        }
        int start = 1 + round * num_people;
        for (int i = 0; i < num_people; ++i) {
            if (candies > start) {
                ans[i] += start;
                candies-=start;
                start++;
            }else{
                ans[i]+=candies;
                break;
            }
        }
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().distributeCandies(60,4);
    return 0;
}
