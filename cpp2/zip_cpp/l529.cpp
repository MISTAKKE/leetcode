#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        howmuchinit(board);
        dfs(board, x, y);
        howmuchover(board, x, y);
        return board;
    }
    bool valid(vector<vector<char>>& board, int x, int y)
    {
        if(x>=0 && x<board.size() && y>=0 && y<board[0].size())
            return true;
        return false;
    }
    void howmuchinit(vector<vector<char>>& board)
    {
        for(int x = 0;x<board.size();++x)
            for(int y=0;y<board[0].size();++y)
            {
                if(board[x][y] != 'M')
                    continue;
                //E num
                for(int i = -1;i<2;++i)
                    for(int j = -1;j<2;++j)
                    {
                        int newx = x + i;
                        int newy = y + j;
                        if(valid(board, newx, newy) && (board[newx][newy]=='E' || (board[newx][newy]>0 && board[newx][newy]<8)))
                        {
                            if(board[newx][newy]=='E')
                                board[newx][newy] = 1;
                            else
                                board[newx][newy] +=1;
                        }
                    }
            }
    }
    void howmuchover(vector<vector<char>>& board, int a,int b)
    {
        for(int x = 0;x<board.size();++x)
            for(int y=0;y<board[0].size();++y)
            {
                if(board[x][y] >= 1 && board[x][y]<=8)
                {
                    bool stop = false;
                    for(int i = -1;i<2;++i)
                        for(int j = -1;j<2;++j)
                        {
                            int newx = x + i;
                            int newy = y + j;
                            if(valid(board, newx, newy) && board[newx][newy] =='B')
                                stop = true;
                        }
                    if(stop == false && !(a==x && b==y))
                        board[x][y] = 'E';
                    else
                        board[x][y] += '0';
                }
            }
    }
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        int now = board[x][y];
        if(now != 'E')
        {
            return;
        }
        board[x][y] = 'B';
        for(int i = -1;i<2;++i)
            for(int j = -1;j<2;++j)
            {
                int newx = x + i;
                int newy = y + j;
                if(valid(board, newx, newy) && board[newx][newy] == 'E')
                    dfs(board, newx, newy);
            }
        
    }
};


int main()
{
    Solution A;
    vector<vector<char>> vec{{'B','B','B','B','B','B','1','E'},{'B','1','1','1','B','B','1','M'},{'1','2','M','1','B','B','1','1'},{'M','2','1','1','B','B','B','B'},{'1','1','B','B','B','B','B','B'},{'B','B','B','B','B','B','B','B'},{'B','1','2','2','1','B','B','B'},{'B','1','M','M','1','B','B','B'}};
    vector<int> res{0, 7};
    show(vec);
    show(A.updateBoard(vec, res));

    vector<vector<char>> r{{'B','B','B','B','B','B','1','1'},{'B','1','1','1','B','B','1','M'},{'1','2','M','1','B','B','1','1'},{'M','2','1','1','B','B','B','B'},{'1','1','B','B','B','B','B','B'},{'B','B','B','B','B','B','B','B'},{'B','1','2','2','1','B','B','B'},{'B','1','M','M','1','B','B','B'}};
    show(r);

    return 0;
}
