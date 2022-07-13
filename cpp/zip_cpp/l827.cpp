#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    // 23:32
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> father(n * n, -1);
        set<int> able;
        // init
        show(father);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k <= 1; ++k) {
                        if (isok(n, i + dx[k], j + dy[k])) {
                            if (grid[i + dx[k]][j + dy[k]] == 0) {
                                able.insert((i + dx[k]) * n + j + dy[k]);
                            }
                            else {
                                cout << "i=" << i << " j=" << j << " i + dx[k]=" << i + dx[k]
                                     << " j + dy[k]=" << j + dy[k] << endl;
                                merge(father, i * n + j, (i + dx[k]) * n + j + dy[k]);
                            }
                        }
                    }
                    for (int k = 2; k <= 3; ++k) {
                        if (isok(n, i + dx[k], j + dy[k])) {
                            if (grid[i + dx[k]][j + dy[k]] == 0) {
                                able.insert((i + dx[k]) * n + j + dy[k]);
                            }
                        }
                    }
                }
            }
        }
        map<int, int> fatherval;
        int maxval = 1;
        for (int i = 0; i < n * n; ++i) {
            if (grid[i / n][i % n] == 1) {
                int f = find(father, i);
                fatherval[f] += 1;
                maxval = max(maxval, fatherval[f]);
            }
        }
        show(father);
        show(able);
        show(fatherval);
        // merge now
        for (auto it : able) {
            int i = it / n;
            int j = it % n;
            set<int> total;
            int totalval = 0;
            for (int k = 0; k <= 3; ++k) {
                if (isok(n, i + dx[k], j + dy[k]) && grid[i + dx[k]][j + dy[k]]) {
                    total.insert(find(father, (i + dx[k]) * n + j + dy[k]));
                }
            }
            cout << "it=" << it << endl;
            show(total);
            for (auto it : total) {
                totalval += fatherval[it];
            }
            maxval = max(maxval, totalval + 1);
        }
        return maxval;
    }
    bool isok(int n, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return false;
        return true;
    }
    int find(vector<int>& father, int i) {
        if (father[i] == -1) {
            father[i] = i;
            return i;
        }
        int son = father[i];
        while (i != father[i]) {
            i = father[i];
        }
        while (son != i) {
            int tmp = father[son];
            father[son] = i;
            son = tmp;
        }
        return i;
    }
    void merge(vector<int>& father, int i, int j) {
        int fi = find(father, i);
        int fj = find(father, j);
        father[fi] = fj;
    }
};

int main() {
    Solution A;
    vector<vector<int>> grid{{0, 1}, {0, 0}};
    cout << A.largestIsland(grid) << endl;

    return 0;
}
