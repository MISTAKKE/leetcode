#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> father(n, 0);
        for (int i = 0; i < n; ++i)
            father[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j] == 1)
                    merge(father, i, j);
        for (int i = 0; i < n; ++i) {
            if (father[i] == i)
                cnt += 1;
        }
        return cnt;
    }
};

int main() {
    Solution A;
    vector<vector<int>> vec{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << A.findCircleNum(vec) << endl;
    return 0;
}
