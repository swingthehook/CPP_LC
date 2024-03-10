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

class Solution {
public:
    //简单模拟
    string getHint(string secret, string guess) {
        int mapA[10] = {0};
        int mapB[10] = {0};
        int A = 0, B = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i])
                A++;
            else {
                mapA[secret[i] - '0']++;
                mapB[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            B += mapA[i] < mapB[i]?mapA[i]:mapB[i];
        }
        string ans;
        ans+= to_string(A);
        ans+="A";
        ans+= to_string(B);
        ans+="B";
        return ans;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().findKOr(nums, 4);
    return 0;
}
