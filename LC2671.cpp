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

class FrequencyTracker {
public:
    /*一个数组记录数字-频率
     * 一个数组记录频率-个数
     * 把预处理做完，达到o(1)的查询效率
     * map虽然是红黑树，但logn的查询满足不了大量数据
     * */
    vector<int> frqc;
    vector<int> count;
    FrequencyTracker() {
        frqc.resize(1e5+1);
        count.resize(1e5+1);
    }

    void add(int number) {
        if(frqc[number] == 0){
            frqc[number]++;
            count[1]++;
        } else{
            count[frqc[number]]--;
            frqc[number]++;
            count[frqc[number]]++;
        }
    }

    void deleteOne(int number) {
        if(frqc[number] == 0)
            return;
        count[frqc[number]]--;
        frqc[number]--;
        count[frqc[number]]++;
    }

    bool hasFrequency(int frequency) {
        return count[frequency]!=0;
    }
};

int main() {
    int num = 2;
    vector<int> nums = {7,12,9,8,9,15};
    auto f = FrequencyTracker();
    f.add(3);
    f.add(3);
    cout<<f.hasFrequency(2);
    return 0;
}
