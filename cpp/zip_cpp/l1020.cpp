#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] 的值为 0 或 1

*/

//Class Solution
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i= 0;i<grid.size();++i){
            for(int j= 0;j<grid[0].size();++j){
                if((i==0||j==0||i==grid.size()-1||j==grid[0].size()-1)&&grid[i][j]==1){
                    grid[i][j] = 2;
                    dfs(grid, i, j);
                }
            }
        }
        int cnt = 0;
        for(int i= 0;i<grid.size();++i){
            for(int j= 0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i>1 && i-1>=0 && grid[i-1][j]==1){
            grid[i-1][j] = 2;
            dfs(grid,i-1,j);
        }
        if(i<grid.size()-1 && (i+1 <= grid.size() -1) && grid[i+1][j]==1){
            grid[i+1][j] = 2;
            dfs(grid,i+1,j);
        }
        if(j>1 && j-1>=0 && grid[i][j-1]==1){
            grid[i][j-1] = 2;
            dfs(grid,i,j-1);
        }
        if(j<grid[0].size()-1 && (j+1 <= grid[0].size() -1) && grid[i][j+1]==1){
            grid[i][j+1] = 2;
            dfs(grid,i,j+1);
        }
    }
};
int main()
{
    Solution A;
    // vector<vector<int>>vec{{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    // vector<vector<int>>vec{{0},{1},{1},{0},{0}};
    vector<vector<int>>vec{{0,1,1,0,0,1,1,1,0,0,0,0,1},{0,0,0,0,0,1,1,1,1,0,1,0,1},{1,0,1,0,1,0,1,1,0,1,0,1,0},{0,0,1,0,0,0,1,0,0,1,0,0,0},{1,1,0,0,1,0,1,0,0,0,1,0,1},{0,0,0,1,1,0,1,0,1,0,0,0,1},{1,0,1,1,0,1,1,1,1,1,1,0,0},{0,0,1,1,0,0,0,0,1,1,1,1,0},{1,0,1,1,1,0,1,1,1,0,0,1,0},{1,1,1,0,1,0,0,0,1,1,1,0,1}};
    cout<<A.numEnclaves(vec)<<endl;

    return 0;
}
