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
        int ret = 0;
        vector<int> father(grid.size() * grid.size(), -1);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] == 1) {
                    father[i * grid.size() + j] = i * grid.size() + j;
                    ret += 1;
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < grid.size(); ++k) {
                        if (k != j && grid[i][k] == 1) {
                            merge(father, i * grid.size() + j, i * grid.size() + k);
                        }
                        if (k != i && grid[k][j] == 1) {
                            merge(father, i * grid.size() + j, k * grid.size() + j);
                        }
                    }
                }
            }
        }
        map<int, int> fathercnt;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                fathercnt[find(father, i * grid.size() + j)] += 1;
            }
        }
        return ret;
        for (auto& it : fathercnt) {
            if (it.second == 1) {
                ret -= 1;
            }
        }
        return ret;
    }

    int find(vector<int>& father, int i) {
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
        i = find(father, i);
        j = find(father, j);
        father[i] = j;
    }
};

int main() {
    Solution A;
    vector<vector<int>> res{{0, 1}, {1, 0}};
    cout << A.countServers(res) << endl;

    return 0;
}
