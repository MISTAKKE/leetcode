#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> block;
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        block = vector<vector<bool>>(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    int blockidx = i / 3 * 3 + j / 3;
                    row[i][val] = true;
                    col[j][val] = true;
                    block[blockidx][val] = true;
                }
            }
        }
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board) {
        // find the first dot
        int i = 0;  // 0 -> 8
        int j = 0;
        while (board[i][j] != '.') {
            if (j != 8) {
                ++j;
            }
            else {
                j = 0;
                if (++i == 9) {
                    return true;
                }
            }
        }
        // cout << "i:" << i << " j:" << j << endl;
        int blockidx = i / 3 * 3 + j / 3;
        for (int val = 0; val < 9; ++val) {
            if (!row[i][val] && !col[j][val] && !block[blockidx][val]) {
                // cout << "i:" << i << " j:" << j << " val:" << val << endl;
                row[i][val] = true;
                col[j][val] = true;
                block[blockidx][val] = true;
                board[i][j] = '1' + val;
                if (dfs(board)) {
                    return true;
                }
                else {
                    row[i][val] = false;
                    col[j][val] = false;
                    block[blockidx][val] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
};

int main() {
    Solution A;
    vector<vector<char>> vec{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    A.solveSudoku(vec);
    show(vec);
    return 0;
}
