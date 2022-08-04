#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= stones.length <= 1000
0 <= xi, yi <= 10^4

*/

// Class Solution
class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {
        map<int, int> father;
        map<int, vector<int>> row;
        map<int, vector<int>> col;
        int cnt = 0;

        for (int i = 0; i < stones.size(); ++i) {
            int& a = stones[i][0];
            int& b = stones[i][1];
            row[a].push_back(b);
            col[b].push_back(a);
            cnt += 1;
        }

        for (auto&& c : row) {
            int a = c.first;
            vector<int>& b = c.second;
            for (int i = 0; i < b.size(); ++i) {
                for (int j = i; j < b.size(); ++j) {
                    merge(a * 10000 + b[i], a * 10000 + b[j], father);
                }
            }
        }
        for (auto&& c : col) {
            vector<int>& a = c.second;
            int b = c.first;
            for (int i = 0; i < a.size(); ++i) {
                for (int j = i + 1; j < a.size(); ++j) {
                    merge(a[i] * 10000 + b, a[j] * 10000 + b, father);
                }
            }
        }
        for (auto&& c : father) {
            if (c.first == c.second) {
                cnt -= 1;
            }
        }
        return cnt;
    }
    void merge(int i, int j, map<int, int>& father) {
        int fi = find(i, father);
        int fj = find(j, father);
        father[fi] = fj;
    }
    int find(int i, map<int, int>& father) {
        if (father.find(i) == father.end()) {
            father[i] = i;
            return i;
        }
        int init = father[i];
        while (i != father[i]) {
            i = father[i];
        }
        while (init != i) {
            int tmp = father[init];
            father[init] = i;
            init = tmp;
        }
        return i;
    }
};

int main() {
    Solution A;
    vector<vector<int>> stones{{0, 0},
                               {0, 2},
                               {
                                   1,
                                   1,
                               },
                               {2, 0},
                               {2, 2}};
    cout << A.removeStones(stones) << endl;
    return 0;
}
