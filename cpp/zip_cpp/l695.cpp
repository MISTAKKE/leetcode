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
                father[i * m + j] = (grid[i][j] == 1) ? (i * m + j) : -1;
            }
        }
        for (int i = 1; i < grid.size(); ++i) {
            if (grid[i][0] == 1 && grid[i - 1][0] == 1) {
                merge(father, i * m - m, i * m);
            }
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            if (grid[0][j] == 1 && grid[0][j - 1] == 1) {
                merge(father, j - 1, j);
            }
        }
        for (int i = 0; i < father.size(); ++i) {
            if ((i + 1) % m != 0)
                cout << father[i] << "  ";
            else
                cout << father[i] << endl;
        }
        cout << endl;
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
        for (int i = 0; i < father.size(); ++i) {
            if ((i + 1) % m != 0)
                cout << father[i] << "  ";
            else
                cout << father[i] << endl;
        }
        int maxval{0};
        map<int, int> mp;
        for (int i = 0; i < father.size(); ++i) {
            if (father[i] != -1) {
                int root = find(father, i);
                mp[root] += 1;
                maxval = max(maxval, mp[root]);
            }
        }
        return maxval;
    }
    void merge(vector<int>& father, int i, int j) {
        //过程中的merge 不保证其所有的根都为fi
        int fi = find(father, i);
        while (father[j] != fi) {
            int tmp = father[j];
            father[j] = fi;
            j = tmp;
        }
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
    // vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                          {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    //                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};//6
    // vector<vector<int>> grid{{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};  // 4
    vector<vector<int>> grid{{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};  // 4
    cout << A.maxAreaOfIsland(grid) << endl;
    return 0;
}
