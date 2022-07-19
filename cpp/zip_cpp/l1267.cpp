#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
*/

// Class Solution
class Solution {
  public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0);
        vector<int> col(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] && (row[i] >= 2 || col[j] >= 2)) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};

class Solution1 {
  public:
    int countServers(vector<vector<int>>& grid) {
        int ret = 0;
        vector<int> father(grid.size() * grid[0].size(), -1);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    father[i * grid[0].size() + j] = i * grid[0].size() + j;
                    ret += 1;
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < grid[0].size(); ++k) {
                        if (k != j && grid[i][k] == 1) {
                            merge(father, i * grid[0].size() + j, i * grid[0].size() + k);
                        }
                    }
                    for (int k = 0; k < grid.size(); ++k) {
                        if (k != i && grid[k][j] == 1) {
                            merge(father, i * grid[0].size() + j, k * grid[0].size() + j);
                        }
                    }
                }
            }
        }
        map<int, int> fathercnt;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    fathercnt[find(father, i * grid[0].size() + j)] += 1;
                }
            }
        }

        for (auto& it : fathercnt) {
            if (it.second == 1) {
                ret -= 1;
            }
        }
        return ret;
    }

    int find(vector<int>& father, int i) {
        int init = i;
        while (i != father[i]) {
            i = father[i];
        }
        while (init != i) {
            int tmp = father[init];
            father[init] = i;
            init = tmp;
        }
        return i;
    }

    void merge(vector<int>& father, int i, int j) {
        father[find(father, i)] = find(father, j);
    }
};

int main() {
    Solution A;
    // vector<vector<int>> res{{1, 0, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}};  // 3
    vector<vector<int>> res{{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    // vector<vector<int>> res{{1, 0}, {1, 1}};  //3
    cout << A.countServers(res) << endl;

    return 0;
}
