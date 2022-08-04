#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool valid(int i, int j, vector<vector<int>>& matrix) {
        if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size())
            return true;
        return false;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int maxval = 0;
        vector<vector<int>> p(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, p, matrix);
                maxval = max(maxval, p[i][j]);
            }
        }
        show(p);
        return maxval + 1;
    }
    void dfs(int i, int j, vector<vector<int>>& p, vector<vector<int>>& matrix) {
        if (p[i][j] != -1)
            return;
        for (int k = 0; k < 4; ++k) {
            if (valid(dx[k] + i, dy[k] + j, matrix) && matrix[dx[k] + i][dy[k] + j] < matrix[i][j]) {
                dfs(dx[k] + i, dy[k] + j, p, matrix);
                p[i][j] = max(p[i][j], p[dx[k] + i][dy[k] + j] + 1);
            }
        }
        if (p[i][j] == -1)
            p[i][j] = 0;
    }
};

int main() {
    Solution A;
    vector<vector<int>> matrix{{1, 2, 3}, {0, -11, -2}, {-10, -9, -8}};
    print(A.longestIncreasingPath(matrix));

    return 0;
}
