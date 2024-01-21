#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int len = nums.size();
        vector<int> ans(len);
        int count = len - 1;
        for (int i = 0, j = len - 1; i <= j;) {
            if (abs(nums[i]) < abs(nums[j])) {
                ans[count--] = nums[j] * nums[j];
                --j;
            } else {
                ans[count--] = nums[i] * nums[i];
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
