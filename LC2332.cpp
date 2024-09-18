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
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        int i = 0, j = 0;
        int ans=-1;
        while (i < buses.size() && j < passengers.size()) {
            if (buses[i] < passengers[j]) {
                ans = buses[i];
                ++i;
            } else {
                int space = capacity;
                while (j < passengers.size() && space && passengers[j] <= buses[i]) {
                    ++j;
                    space--;
                }
                if (space > 0) {
                    int tans = buses[i];
                    int cj=j-1;
                    while (cj>=0 && tans == passengers[cj]){
                        --tans;
                        --cj;
                    }
                    ans = tans;
                } else {
                    int cj = j-1;
                    while (cj > 0 && passengers[cj] == passengers[cj - 1]+1) --cj;
                    ans = passengers[cj] - 1;
                }
                ++i;
            }
        }
        if(i<buses.size())
            ans = buses.back();
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums1 = {2,3};
    vector<int> nums2 = {2,3};

    Solution().latestTimeCatchTheBus(nums1, nums2, 2);
    return 0;
}
