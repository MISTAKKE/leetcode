#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<int> dx{0, -1, 0, 1};
    vector<int> dy{1, 0, -1, 0};
    bool check(vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'y';
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (check(board, ni, nj) && board[ni][nj] == 'O')
                dfs(board, ni, nj);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i != 0 && j != 0 && i != n - 1 && j != m - 1)
                    continue;
                if (board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'y')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution A;
    vector<vector<char>> cr{
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'X', 'X'}, {'X', 'O', 'X', 'X'}};
    A.solve(cr);
    show(cr);

    return 0;
}
