#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
*/

// Class Solution

class Solution {
  public:
    int countServers(vector<vector<int>>& grid) {}

    int find(vector<int>& father, int i) {
        int son = father[i];
        while (i != father[i]) {
            i = father[i];
        }
        while (son != i) {
            int tmp = father[son];
            father[son] = i;
            son = tmp;
        }
        return i;
    }

    void merge(vector<int>& father, int i, int j) {
        i = find(father, i);
        j = find(father, j);
        father[i] = j;
    }
};

int main() {
    Solution A;

    return 0;
}
