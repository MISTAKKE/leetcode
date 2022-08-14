#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<int> father;
    vector<int> rank;
    /*
        set:
            father 的 rank = 1
            merge时 相同的话对其father += 1
        get:
            merge时 rank较小的为father

    */
    int find(int idx) {
        int son = idx;
        while (idx != father[idx]) {
            idx = father[idx];
        }
        while (idx != son) {
            int f = father[son];
            father[son] = idx;
            son = f;
        }
        return idx;
    }
    void merge(int i, int j) {
        i = find(i);
        j = find(j);
        if (rank[i] == rank[j]) {
            rank[j] += 1;
            father[j] = i;
        }
        if (rank[i] < rank[j]) {
            father[j] = i;
        }
        else {
            father[j] = i;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        father.resize(m * n, -1);
        rank.resize(m * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    father[i * m + j] = i * m + j;
                    rank[i * m + j] = 1;
                    if (i > 0 && grid[i - 1][j] == '1') {
                        merge(i * m + j, i * m + j - m);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        merge(i * m + j, i * m + j - 1);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (father[i * m + j] == i * m + j) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
// Class Solution
class Solution2 {
  public:
    vector<int> parent;
    int find(int idx) {
        while (idx != parent[idx]) {
            idx = parent[idx];
        }
        return idx;
    }
    void merge(int i, int j) {
        i = find(i);
        j = find(j);
        parent[j] = i;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0)
                    continue;
                parent.push_back(i * m + j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0')
                    continue;
                if (j < m - 1 && grid[i][j + 1] == '1')
                    merge(i * m + j, i * m + j + 1);
                if (i < n - 1 && grid[i + 1][j] == '1')
                    merge(i * m + j, i * m + j + m);
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && find(i * m + j) == i * m + j)
                    count += 1;
            }
        }
        show(parent);
        return count;
    }
};

int main() {
    Solution A;
    vector<vector<char>> vec{{'0'}
        // {'1', '1', '0', '0', '0'},
        // {'1', '1', '0', '0', '0'},
        // {'0', '0', '1', '1', '0'},
        // {'0', '0', '0', '1', '1'},
    };
    cout << A.numIslands(vec) << endl;
    return 0;
}
