#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> dx{0, 1, 0, -1};
    vector<int> dy{-1, 0, 1, 0};
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (dfs(board, visited, 1, word, i, j))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        return false;
    }
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int idx, const string &word, int di, int dj)
    {
        // cout << "dfs word:" << word << " idx:" << idx << " i:" << di << " j:" << dj << endl;
        // show(visited);
        if (idx == word.size())
            return true;
        for (int i = 0; i < 4; ++i)
        {
            int ddi = di + dx[i];
            int ddj = dj + dy[i];
            if (isok(ddi, ddj, board) && !visited[ddi][ddj] && word[idx] == board[ddi][ddj])
            {

                visited[ddi][ddj] = true;
                if (dfs(board, visited, idx + 1, word, ddi, ddj))
                    return true;
                visited[ddi][ddj] = false;
            }
        }
        return false;
    }
    bool isok(int x, int y, vector<vector<char>> &board)
    {
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size())
            return false;
        return true;
    }
};

int main()
{
    Solution A;
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    vector<string> words{"ABCCED", "SEE", "ABCB"};
    for (auto word : words)
    {
        cout << A.exist(board, word) << endl;
    }
    // 给定 word = "ABCCED", 返回 true
    // 给定 word = "SEE", 返回 true
    // 给定 word = "ABCB", 返回 false

    return 0;
}
