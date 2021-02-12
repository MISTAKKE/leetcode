#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1 //并查集1
{
public:
    class Node
    {
    public:
        int x;
        int y;
        int val;
        Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_){};
        bool operator<(const Node &b) const
        {
            return val > b.val;
        }
    };
    bool isok(int x, int y, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> father(n * n, 0);
        priority_queue<Node, vector<Node>, less<Node>> neighbor;
        for (int i = 0; i < n * n; ++i)
            father[i] = i;
        neighbor.push(Node(0, 1, grid[0][1]));
        neighbor.push(Node(1, 0, grid[1][0]));
        for (int nowval = max(2 * n - 2, grid[0][0]); nowval < n * n; ++nowval) //2*n-2 最小需要这么多节点  g[0][0] 初始值的位置
        {
            while (!neighbor.empty())
            {
                Node p = neighbor.top();
                if (p.val <= nowval)
                {
                    father[p.val] = grid[0][0];
                    neighbor.pop();             //当前值低于阈值，merge进去
                    for (int i = 0; i < 4; ++i) //将附近的小值也尝试merge进去
                    {
                        int x = p.x + dx[i];
                        int y = p.y + dy[i];
                        if (isok(x, y, n) && father[grid[x][y]] != grid[0][0]) //不越界，且未merge过
                        {
                            neighbor.push(Node(x, y, grid[x][y]));
                        }
                    }
                }
                else
                    break;
            }
            if (father[grid[n - 1][n - 1]] == grid[0][0]) //在同一个集合就退出
                return nowval;
        }
    }
};

class Solution2 //并查集2 用int代替node
{
public:
    bool isok(int x, int y, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> father(n * n, 0);
        set<int> neighbor;
        for (int i = 0; i < n * n; ++i)
            father[i] = i;
        neighbor.insert(0 + 1 * n + grid[0][1] * n * n);
        neighbor.insert((1 + 0 * n + grid[1][0] * n * n));
        for (int nowval = max(2 * n - 2, grid[0][0]); nowval < n * n; ++nowval) //2*n-2 最小需要这么多节点  g[0][0] 初始值的位置
        {
            while (!neighbor.empty())
            {
                int p = *neighbor.begin();
                int pval = p / n / n;
                p -= pval * n * n;
                int py = p / n;
                p -= py * n;
                int px = p;
                if (pval <= nowval)
                {
                    father[pval] = grid[0][0];
                    neighbor.erase(px + py * n + pval * n * n); //当前值低于阈值，merge进去
                    for (int i = 0; i < 4; ++i)                 //将附近的小值也尝试merge进去
                    {
                        int x = px + dx[i];
                        int y = py + dy[i];
                        if (isok(x, y, n) && father[grid[x][y]] != grid[0][0]) //不越界，且未merge过
                        {
                            neighbor.insert(x + y * n + grid[x][y] * n * n);
                        }
                    }
                }
                else
                    break;
            }
            if (father[grid[n - 1][n - 1]] == grid[0][0]) //在同一个集合就退出
                return nowval;
        }
    }
};


int main()
{
    Solution A;
    //vector<vector<int>> res{{3, 1}, {2, 0}}; //3
    vector<vector<int>> res{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}}; //16
    show(res);
    cout << A.swimInWater(res) << endl;
    return 0;
}
