#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

n == graph.length
n == graph[i].length
2 <= n <= 300
graph[i][j] 是 0 或 1.
graph[i][j] == graph[j][i]
graph[i][i] == 1
1 <= initial.length < n
0 <= initial[i] <= n - 1
 initial 中每个整数都不同
*/

// Class Solution

class Solution {
  public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        vector<bool> clean(graph.size(), true);
        int retidx = initial[0];
        for (auto& c : initial) {
            clean[c] = false;
            retidx = min(retidx, c);
        }
        vector<set<int>> effectby(graph.size(), set<int>{});
        for (auto& c : initial) {
            dfs(graph, clean, effectby, c, c);
        }
        map<int, int> effectcnt;
        int maxval{0};
        for (auto& it : effectby) {
            show(it);
            if (it.size() == 1) {
                effectcnt[*it.begin()] += 1;
                if (effectcnt[*it.begin()] > maxval) {
                    retidx = *it.begin();
                    maxval = effectcnt[*it.begin()];
                }
                else if (effectcnt[*it.begin()] == maxval) {
                    retidx = min(retidx, *it.begin());
                }
            }
        }
        // show(effectcnt);
        return retidx == graph.size() ? 0 : retidx;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& clean, vector<set<int>>& effectby, int idx, int now) {
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[now][i] == 1 && clean[i] && !effectby[i].count(idx)) {
                effectby[i].insert(idx);
                dfs(graph, clean, effectby, idx, i);
            }
        }
    }
};
int main() {
    Solution A;
    vector<vector<int>> vec{{1, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 1}};
    vector<int> dd{3, 0};
    cout << A.minMalwareSpread(vec, dd) << endl;
    return 0;
}
