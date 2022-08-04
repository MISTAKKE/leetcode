#include "../tool/helper.cpp"
using namespace std;

/*
description:
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。
输入：
[
  " /",
  "/ "
]
输出：2
*/

class Cunion {
  public:
    Cunion(int count) {
        parent.resize(count);
        rank.resize(count);
        for (int i = 0; i < count; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int idx) {
        int son = idx;
        while (idx != parent[idx]) {
            idx = parent[idx];
        }
        while (son != idx) {
            int tmp = parent[son];
            parent[son] = idx;
            son = tmp;
        }
        return idx;
    }

    void merge(int id1, int id2) {
        int p1 = find(id1);
        int p2 = find(id2);
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        }
        else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        }
        else {
            parent[p1] = p2;
            rank[p2] += 1;
        }
    }

  private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
  public:
    int regionsBySlashes(vector<string>& grid) {
        int count = grid.size() * grid.size() * 4;
        Cunion c = Cunion(count);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int idx = 4 * (i * grid.size() + j);
                if (grid[i][j] == ' ') {
                    c.merge(idx, idx + 1);
                    c.merge(idx, idx + 2);
                    c.merge(idx + 2, idx + 3);
                }
                else if (grid[i][j] == '/') {
                    c.merge(idx, idx + 1);
                    c.merge(idx + 2, idx + 3);
                }
                else {
                    c.merge(idx, idx + 3);
                    c.merge(idx + 1, idx + 2);
                }
                if (j != grid.size() - 1) {
                    c.merge(idx + 3, idx + 5);
                }
                if (i != grid.size() - 1) {
                    c.merge(idx + 2, idx + grid.size() * 4);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < grid.size() * grid.size() * 4; ++i) {
            if (c.find(i) == i)
                ret += 1;
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<std::string> str{"/1", "1/"};
    cout << A.regionsBySlashes(str) << endl;

    return 0;
}
