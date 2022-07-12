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
        vector<int> father(n * n, 0);
        set<int> able;
        // init
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int dx = -1; dx <= 1; dx += 2) {
                        for (int dy = -1; dy <= 1; dy += 2) {
                            if (isok(n, i + di, j + dy)) {
                                if (grid[i + di][j + dy]) {
                                    merge(father, i + di, j + dy);
                                }
                            }
                        }
                    }
                }
            }
        }
        // merge now
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ;
            }
        }
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

    return 0;
}
