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
    string capitalizeTitle(string title) {
        int fast = 0, slow = 0;
        while (fast < title.size()) {
            while (title[fast]!=' ' && fast<title.size()){
                title[fast] = tolower(title[fast]);
                fast ++;
            }
            if(fast - slow >2)
                title[slow] = toupper(title[slow]);
            fast++;
            slow = fast;
        }
        if(fast != slow && fast - slow > 2)
            title[slow] = toupper(title[slow]);
        return title;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7, 12, 9, 8, 9, 15};
    Solution().findKOr(nums, 4);
    return 0;
}
