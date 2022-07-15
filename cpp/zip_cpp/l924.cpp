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
            effect[initial[i]].insert(initial[i]);
            reverse[initial[i]].insert(initial[i]);
            dfs(graph, effect, reverse, initial[i], initial[i]);
        }

        cout << "show graph" << endl;
        for (int i = 0; i < graph.size(); ++i)
            show(graph[i]);
        cout << "show effect" << endl;
        for (int i = 0; i < effect.size(); ++i)
            show(effect[i]);
        cout << "show reverse" << endl;
        for (int i = 0; i < reverse.size(); ++i)
            show(reverse[i]);

        for (int i = 0; i < initial.size(); ++i) {
            if (reverse[initial[i]].size() != 1)
                continue;
            int val = 0;
            for (auto it : effect[initial[i]]) {
                if (reverse[it].size() == 1) {
                    val += 1;
                }
            }
            if (val > maxval) {
                minidx = initial[i];
                maxval = val;
            }
            else if (val == maxval) {
                minidx = min(minidx, initial[i]);
            }
        }
        return minidx;
    }
    void dfs(vector<vector<int>>& graph, vector<set<int>>& effect, vector<set<int>>& reverse, int i, int k) {
        for (int j = 0; j < graph.size(); ++j) {
            if (graph[k][j] == 1 && effect[i].count(j) == 0) {
                effect[i].insert(j);
                reverse[j].insert(i);
                dfs(graph, effect, reverse, i, j);
            }
        }
    }
};
int main() {
    Solution A;
    vector<vector<int>> graph{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<int> initial{0, 1, 2};
    cout << A.minMalwareSpread(graph, initial) << endl;

    return 0;
}
