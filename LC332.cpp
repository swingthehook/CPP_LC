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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int total;
    int visited = 0;
    bool cont = true;
    // RBT是有序的，不要存数组再排序了
    unordered_map<string, map<string,int>> mp;
    vector<string> path;
    void rec(string start) {
        if (!cont)
            return;
        path.push_back(start);
        visited++;
        if (visited == total)
            cont = false;
        //要引用，key要const，因为不能修改key，不引用会无法修改原对象，而是拷贝的副本
        for (pair<const string, int>& each: mp[start])
            if(each.second>0){
                each.second--;
                rec(each.first);
                if (!cont)
                    return;
                each.second++;
            }
        if (!cont)
            return;
        path.pop_back();
        visited--;
    }

    static bool cmp(pair<string,bool> p1,pair<string,bool> p2){
        return p1.first<p2.first;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        mp.clear();
        total = tickets.size() + 1;
        for (auto each: tickets) {
            mp[each[0]][each[1]]++;
        }
        rec("JFK");
        return path;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    vector<vector<string>> tick = {
            {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}
    };
    Solution().findItinerary(tick);
    return 0;
}
