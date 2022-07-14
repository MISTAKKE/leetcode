#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        int maxval = 0;
        int minidx = n - 1;
        vector<set<int>> effect(n, set<int>{});
        vector<set<int>> reverse(n, set<int>{});
        for (int i = 0; i < initial.size(); ++i) {
            init(graph, effect, reverse, initial[i]);
        }
        for (int i = 0; i < initial.size(); ++i) {
            int val = 0;
            for (auto it : effect[initial[i]]) {
                if (reverse[it].size() == 1) {
                    val += 1;
                }
            }
            if (val >= maxval) {
                minidx = i;
            }
        }
        return minidx;
    }
    void init(vector<vector<int>>& graph, vector<set<int>>& effect, vector<set<int>>& reverse, int i) {
        for (int k = 0; k < graph.size(); ++k) {
            if (graph[i][k] == 1 && effect.count(k) == 0) {
                effect[i].insert(k);
                reverse[k].insert(i);
                dfs(graph, effect, reverse, i, j);
            }
        }
    }
};

int main() {
    Solution A;

    return 0;
}
