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
    //用bfs而不是dfs，用两个哈希表，而不是队列
    //只需要检查上一层，两个hash table交替存储再swap即可
    int maxMoves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> h1, h2;//存的是可以走的块
        for (int i = 0; i < m; ++i) {
            h1.emplace(i);
        }
        for (int j = 1; j < n; ++j) {
            h2.clear();
            for (auto i: h1) {
                for (int i2 = i - 1; i2 <= i + 1; ++i2) {
                    if (i2 >= 0 && i2 < m && grid[i2][j] > grid[i][j - 1])
                        h2.emplace(i2);
                }
            }
            swap(h1, h2);
            if (h1.empty())
                return j - 1;
        }
        return n - 1;
    }
};

int main() {
    vector<vector<int>> nums = {{1000000, 92910, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068},
                                {1069,    1070,  1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118}};
    Solution().maxMoves(nums);
    return 0;
}
