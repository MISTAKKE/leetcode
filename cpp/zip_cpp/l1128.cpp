#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution {
  public:
    int numEquivDominoPairs1(vector<vector<int>>& dominoes) {
        if (dominoes.size() == 0)
            return 0;
        sort(dominoes.begin(), dominoes.end(), comp);
        int i = 0;
        int initval = min(dominoes[i][0] * 10 + dominoes[i][1], dominoes[i][1] * 10 + dominoes[i][0]);
        int ret = 0;
        int samecnt = 0;
        for (int i = 1; i < dominoes.size(); ++i) {
            int val = min(dominoes[i][0] * 10 + dominoes[i][1], dominoes[i][1] * 10 + dominoes[i][0]);
            if (val == initval)
                samecnt++;
            else {
                ret += samecnt * (samecnt + 1) / 2;
                samecnt = 0;
            }
            initval = val;
        }
        ret += samecnt * (samecnt + 1) / 2;
        return ret;
    }

    static bool comp(const vector<int>& a, const vector<int>& b) {
        int vala = min(a[0] * 10 + a[1], a[1] * 10 + a[0]);
        int valb = min(b[0] * 10 + b[1], b[1] * 10 + b[0]);
        return vala < valb;
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100, 0);
        int ret = 0;
        for (auto c : dominoes) {
            int val = min(c[0] * 10 + c[1], c[1] * 10 + c[0]);
            ret += num[val];
            num[val]++;
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<vector<int>> dominoes{{1, 2}, {2, 1}, {3, 4}, {2, 8}, {8, 2}, {4, 2}, {2, 4}, {2, 1}};
    cout << A.numEquivDominoPairs(dominoes) << endl;
    return 0;
}
