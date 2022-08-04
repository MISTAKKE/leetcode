#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution1  //并查集1
{
  public:
    class Node {
      public:
        int x;
        int y;
        int val;
        Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_){};
        bool operator<(const Node& b) const {
            return val > b.val;
        }
    };
    bool isok(int x, int y, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> father(n * n, 0);
        priority_queue<Node, vector<Node>, less<Node>> neighbor;
        for (int i = 0; i < n * n; ++i)
            father[i] = i;
        neighbor.push(Node(0, 1, grid[0][1]));
        neighbor.push(Node(1, 0, grid[1][0]));
        for (int nowval = max(2 * n - 2, grid[0][0]); nowval < n * n;
             ++nowval)  // 2*n-2 最小需要这么多节点  g[0][0] 初始值的位置
        {
            while (!neighbor.empty()) {
                Node p = neighbor.top();
                if (p.val <= nowval) {
                    father[p.val] = grid[0][0];
                    neighbor.pop();              //当前值低于阈值，merge进去
                    for (int i = 0; i < 4; ++i)  //将附近的小值也尝试merge进去
                    {
                        int x = p.x + dx[i];
                        int y = p.y + dy[i];
                        if (isok(x, y, n) && father[grid[x][y]] != grid[0][0])  //不越界，且未merge过
                        {
                            neighbor.push(Node(x, y, grid[x][y]));
                        }
                    }
                }
                else
                    break;
            }
            if (father[grid[n - 1][n - 1]] == grid[0][0])  //在同一个集合就退出
                return nowval;
        }
    }
};

class Solution2  //并查集2 用int代替node
{
  public:
    bool isok(int x, int y, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> father(n * n, 0);
        set<int> neighbor;
        for (int i = 0; i < n * n; ++i)
            father[i] = i;
        neighbor.insert(0 + 1 * n + grid[0][1] * n * n);
        neighbor.insert((1 + 0 * n + grid[1][0] * n * n));
        for (int nowval = max(2 * n - 2, grid[0][0]); nowval < n * n;
             ++nowval)  // 2*n-2 最小需要这么多节点  g[0][0] 初始值的位置
        {
            while (!neighbor.empty()) {
                int p = *neighbor.begin();
                int pval = p / n / n;
                p -= pval * n * n;
                int py = p / n;
                p -= py * n;
                int px = p;
                if (pval <= nowval) {
                    father[pval] = grid[0][0];
                    neighbor.erase(px + py * n + pval * n * n);  //当前值低于阈值，merge进去
                    for (int i = 0; i < 4; ++i)                  //将附近的小值也尝试merge进去
                    {
                        int x = px + dx[i];
                        int y = py + dy[i];
                        if (isok(x, y, n) && father[grid[x][y]] != grid[0][0])  //不越界，且未merge过
                        {
                            neighbor.insert(x + y * n + grid[x][y] * n * n);
                        }
                    }
                }
                else
                    break;
            }
            if (father[grid[n - 1][n - 1]] == grid[0][0])  //在同一个集合就退出
                return nowval;
        }
    }
};

class Solution3  // dijkstra
{
  public:
    class Node {
      public:
        int x;
        int y;
        int val;
        Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_){};
        bool operator<(const Node& b) const {
            return val > b.val;
        }
    };
    bool isok(int x, int y, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Node, vector<Node>, less<Node>> q;
        vector<vector<int>> score(n, vector<int>(n, 0));
        vector<vector<int>> visited(n, vector<int>(n, false));
        q.push(Node(0, 0, grid[0][0]));
        score[0][0] = grid[0][0];
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            if (node.x == n - 1 && node.y == n - 1) {
                return score[n - 1][n - 1];
            }
            visited[node.x][node.y] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = node.x + dx[i];
                int ny = node.y + dy[i];
                if (isok(nx, ny, n) && !visited[nx][ny]) {
                    score[nx][ny] = max(score[node.x][node.y], grid[nx][ny]);
                    q.push(Node(nx, ny, grid[nx][ny]));
                }
            }
        }
        return 0;
    }
};

class Solution  // bfs + 二分
{
  public:
    class Node {
      public:
        int x;
        int y;
        Node(int x_, int y_) : x(x_), y(y_){};
    };
    bool isok(int x, int y, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }
    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};
    bool checkok(vector<vector<int>>& grid, int mid) {
        stack<Node> st;
        st.push(Node(0, 0));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        while (!st.empty()) {
            Node p = st.top();
            st.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (isok(nx, ny, grid.size()) && grid[nx][ny] <= mid && !visited[nx][ny]) {
                    if (nx == grid.size() - 1 && ny == grid.size() - 1) {
                        return true;
                    }
                    st.push(Node(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = max(grid[0][0], grid[n - 1][n - 1]) - 1;
        int right = n * n;
        int mid = (left + right) / 2;
        while (1) {
            cout << "before check left:" << left << " mid:" << mid << " right:" << right << endl;
            if (checkok(grid, mid)) {
                cout << "checkout ok mid:" << mid << endl;
                if (left + 1 == mid) {
                    return mid;
                }
                right = mid;
                mid = (left + right) / 2;
            }
            else {
                cout << "checkout not ok mid:" << mid << endl;
                left = mid;
                mid = (left + right + 1) / 2;
            }
        }
        return 0;
    }
};

int main() {
    Solution A;
    // vector<vector<int>> res{{3, 1}, {2, 0}}; //3
    // vector<vector<int>> res{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9,
    // 8, 7, 6}}; //16
    vector<vector<int>> res{{11, 15, 3, 2}, {6, 4, 0, 13}, {5, 8, 9, 10}, {1, 14, 12, 7}};  // 11
    show(res);
    cout << A.swimInWater(res) << endl;
    return 0;
}
