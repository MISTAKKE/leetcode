#include "../tool/helper.cpp"
using namespace std;

/*
description:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/

// Class Solution
class Solution {
  public:
    vector<int> dx{0, 1, 0, -1};
    vector<int> dy{1, 0, -1, 0};
    int direction{0};  // 0(左) 1(下) 2(右) 3(上)
    int nowx{0};
    int nowy{-1};
    int loop{0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int x = nowx + dx[direction];
                int y = nowy + dy[direction];
                if (direction == 0) {
                    if (y == matrix[0].size() - 1 - loop) {
                        direction = 1;
                    }
                }
                else if (direction == 1) {
                    if (x == matrix.size() - 1 - loop) {
                        direction = 2;
                    }
                }
                else if (direction == 2) {
                    if (y == 0 + loop) {
                        direction = 3;
                    }
                }
                else if (direction == 3) {
                    if (x == 1 + loop) {
                        direction = 0;
                        loop += 1;
                    }
                }
                ret.push_back(matrix[x][y]);
                nowx = x;
                nowy = y;
                cout << "x:" << x << " y:" << y << " dir:" << direction << endl;
            }
        }
        return ret;
    }
};
class Solution2 {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 1 left m*n consume  m*n - (m-2)*(n-2) = 2(m + n) - 4
        // 2 left m-1*n-1 consume m + n - 1
        int n = matrix.size();  //行数

        int m = matrix[0].size();  //列数
        vector<int> res;
        vector<int> dx{0, 1, 0, -1};  // ->  ↓  <-  ↑
        vector<int> dy{1, 0, -1, 0};
        int x = 0, y = -1;
        int loop = 0;
        int direction = 0;
        for (int i = 0; i < m * n; ++i) {
            x = x + dx[direction];
            y = y + dy[direction];
            res.push_back(matrix[x][y]);
            if (direction == 0) {
                if (y == m - 1 - loop) {
                    direction = (direction + 1) % 4;
                }
            }
            else if (direction == 1) {
                if (x == n - 1 - loop) {
                    direction = (direction + 1) % 4;
                }
            }
            else if (direction == 2) {
                if (y == loop) {
                    direction = (direction + 1) % 4;
                }
            }
            else if (direction == 3) {
                if (x == 1 + loop) {
                    direction = (direction + 1) % 4;
                    loop += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<vector<int>> res{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // vector<vector<int>> res{{1}, {2}};
    // 1  2  3  4
    // 5  6  7  8
    // 9 10 11  12
    // 13 14 15 16
    show(A.spiralOrder(res));

    return 0;
}
