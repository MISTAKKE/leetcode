#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    // 23:32
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> father(n * n, -1);
        set<int> able;
        // init
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int di = -1; di <= 1; di += 2) {
                        for (int dj = -1; dj <= 1; dj += 2) {
                            if (isok(n, i + di, j + dj)) {
                                if (grid[i + di][j + dj] == 0) {
                                    able.insert((i + di) * n + j + dj);
                                }
                                else {
                                    merge(father, i * n + j, (i + di) * n + j + dj);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
        map<int, int> fatherval;
        for (int i = 0; i < n * n; ++i) {
            fatherval[find(father, i)] += 1;
        }
        show(father);
        show(fatherval);
        // merge now
        int maxval = 1;
        for (auto it : able) {
            int i = it / n;
            int j = it % n;
            set<int> total;
            int totalval = 0;
            for (int di = -1; di <= 1; di += 2) {
                for (int dj = -1; dj <= 1; dj += 2) {
                    if (isok(n, i + di, j + dj)) {
                        total.insert(find(father, (i + di) * n + j + dj));
                    }
                }
            }
            for (auto it : total) {
                totalval += fatherval[it];
            }
            maxval = max(maxval, totalval);
        }
        return maxval + 1;
    }
    bool isok(int n, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return false;
        return true;
    }
    int find(vector<int>& father, int i) {
        if (father[i] == -1) {
            return i;
        }
        int son = i;
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
    vector<vector<int>> grid{{0, 1}, {1, 0}};
    cout << A.largestIsland(grid) << endl;

    return 0;
}
