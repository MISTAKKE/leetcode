#include "../tool/helper.cpp"
using namespace std;

/*
description:

*/

//Class Solution
class Solution1 // 正向 每次生成并查集
{
public:
    int n, m;
    bool isok(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> dx{1, 0};
    vector<int> dy{0, -1}; //下发和左方
    int find(vector<int> &father, int i)
    {
        while (i != father[i])
            i = father[i];
        return i;
    }
    void merge(vector<int> &father, int i, int j)
    {
        i = find(father, i);
        j = find(father, j);
        if (j < m)
            father[i] = j;
        else
            father[j] = i;
    }
    void update(vector<vector<int>> &grid, vector<int> &father)
    {
        //第一行，所有的father都是小于m
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    father[i * m + j] = i * m + j; //初始化 father为自己
            }
        }

        //更新相邻的father
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (isok(nx, ny) && grid[i][j] == 1 && grid[nx][ny] == 1)
                    {
                        merge(father, i * m + j, nx * m + ny);
                    }
                }
            }
        }
    }
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        n = grid.size();    //行数
        m = grid[0].size(); //列数
        vector<int> ret;
        for (auto hit : hits)
        {
            grid[hit[0]][hit[1]] = 0; //被打掉
            vector<int> father(n * m, 0);
            update(grid, father);
            int cnt = 0;
            for (int i = 0; i < n * m; ++i)
                if (find(father, i) >= m) //不小于m，不位于第一行
                {
                    grid[i / m][i % m] = 0;
                    cnt++;
                }
            ret.push_back(cnt);
        }
        return ret;
    }
};

class Solution // 逆向 每次生成并查集
{
public:
    int n, m;
    bool isok(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, -1, 0, 1}; //下发和左方
    int find(vector<int> &father, int i)
    {
        while (i != father[i])
            i = father[i];
        return i;
    }
    void merge(vector<int> &father, int i, int j)
    {
        i = find(father, i);
        j = find(father, j);
        if (j < m)
            father[i] = j;
        else
            father[j] = i;
    }

    int check(vector<vector<int>> &grid, vector<int> &father, vector<int> &hit)
    {
        int cnt = 0;
        grid[hit[0]][hit[1]] = 1; //加进去
        int i = hit[0];
        int j = hit[1];
        for (int k = 0; k < 4; ++k)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (isok(nx, ny) && grid[i][j] == 1 && grid[nx][ny] == 1)
            {
                merge(father, i * m + j, nx * m + ny);
            }
        }
        for (int i = 0; i < father.size(); ++i)
        {
            if (find(father, father[i]) < m)
                cnt += 1;
        }
        return cnt;
    }
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        n = grid.size();    //行数
        m = grid[0].size(); //列数
        vector<int> ret;
        for (auto hit : hits)
        {
            grid[hit[0]][hit[1]] = 0; //被打掉
        }
        vector<int> father(n * m, 0);
        //初始化 father为自己
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    father[i * m + j] = i * m + j;
            }
        }

        //把上下左右的merge
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isok(nx, ny) && grid[i][j] == 1 && grid[nx][ny] == 1)
                    {
                        merge(father, i * m + j, nx * m + ny);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < father.size(); ++i)
        {
            if (find(father, father[i]) < m)
                cnt += 1;
        }
        ret.push_back(cnt);//根小于m的有几个

        for (auto hit : hits)
        {
            ret.push_back(check(grid, father, hit)); //加上hit 根为<m的node新增了几个
        }
        vector<int> res;

        for(int i =1;i<ret.size();++i)
        {
            res.push_back(ret[i] - ret[i-1]);
        }
        return res;
    }
};

int main()
{
    Solution A;
    // vector<vector<int>> grid{{1, 0, 0, 0}, {1, 1, 1, 0}};
    // vector<vector<int>> hits{{1, 0}}; //2

    // vector<vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 0, 0}};
    // vector<vector<int>> hits = {{1, 1}, {1, 0}}; // all 0

    vector<vector<int>> grid{{0, 1, 1, 1, 1}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<vector<int>> hits = {{6,0},{1,0},{4,3},{1,2},{7,1},{6,3},{5,2},{5,1},{2,4},{4,4},{7,3}};// all 0
    show(A.hitBricks(grid, hits));

    return 0;
}
