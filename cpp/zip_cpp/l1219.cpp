#include "../tool/helper.cpp"
using namespace std;

/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：

输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
 

提示：

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
最多 25 个单元格中有黄金。

*/

class Solution {
public:
    int ans, n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool valid(int i, int j, vector<vector<int>> &grid)
    {
        if(i >=0 && i<n && j>=0 && j<m && grid[i][j] >0)
            return true;
        return false;
    }

    int dfs(int i, int j, int cur, vector<vector<int>> &grid)
    {
        cur += grid[i][j];
        ans = max(ans, cur);
        int tmp = grid[i][j];
        grid[i][j] = 0;
        for(int k=0; k<4; ++k)
            if(valid(i+dx[k], j+dy[k], grid))
                dfs(i+dx[k], j+dy[k], cur, grid);

        cur -=tmp; 
        grid[i][j] = tmp;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(valid(i, j, grid))
                    dfs(i, j, 0, grid);
        return ans;
    }
};

int main()
{
    Solution A;    
    vector<vector<int>> grid{
    {0,6,0},
    {5,8,7},
    {0,9,0}
    };
    cout<<A.getMaximumGold(grid);

    return 0;
}
