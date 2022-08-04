#include "../tool/helper.cpp"
using namespace std;

/*
description:

intervals 的长度范围为[1, 3000]。
intervals[i] 长度为 2，分别代表左、右边界。
intervals[i][j] 的值是 [0, 10^8]范围内的整数。

*/

// Class Solution

class Solution {
  public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return (a[1] < b[1]) || ((a[1] == b[1]) && (a[0] > b[0]));
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int s2 = intervals[0][1] - 1;
        int s1 = intervals[0][1];
        int ret = 2;
        for (auto&& interval : intervals) {
            if (interval[0] > s1) {
                ret += 2;
                s2 = interval[1] - 1;
                s1 = interval[1];
            }
            else if (interval[0] > s2) {
                ret += 1;
                s2 = s1;
                s1 = interval[1];
            }
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    cout << A.intersectionSizeTwo(intervals) << endl;
    return 0;
}
