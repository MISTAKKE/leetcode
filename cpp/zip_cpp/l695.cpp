#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> father(n * m, 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                father[i * m + j] = (grid[i][j] == 1) ? i * m + j : -1;
            }
        }
        for (int i = 1; i < grid.size(); ++i) {
            if (grid[i][0] == 1 && grid[i - 1][0] == 1) {
                merge(father, i * m, i * m + m);
            }
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            if (grid[0][j] == 1 && grid[0][j - 1] == 1) {
                merge(father, j - 1, j);
            }
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && grid[i][j - 1] == 1) {
                    merge(father, i * m + j - 1, i * m + j);
                }
                if (grid[i][j] == 1 && grid[i - 1][j] == 1) {
                    merge(father, i * m + j - m, i * m + j);
                }
            }
        }

        int ret{0};
        for (int i = 0; i < father.size(); ++i) {
            if (father[i] == i) {
                ret += 1;
            }
        }
        return ret;
    }
    void merge(vector<int>& father, int i, int j) {
        int fi = find(father, i);
        int fj = find(father, j);
        father[j] = i;
    }
    int find(vector<int>& father, int i) {
        int tmp = i;
        while (father[i] != i) {
            i = father[i];
        }
        while (father[tmp] != i) {
            int t = father[tmp];
            father[tmp] = i;
            tmp = t;
        }
        return i;
    }
};

int main() {
    Solution A;
    vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << A.maxAreaOfIsland(grid) << endl;
    return 0;
}
