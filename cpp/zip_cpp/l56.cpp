#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            int last_end = res.back()[1];
            if (last_end < intervals[i][0]) {
                res.push_back(intervals[i]);
            }
            else {
                res.back()[1] = max(intervals[i][1], last_end);
            }
        }
        return res;
    }
};
int main() {
    Solution A;
    vector<vector<int>> intervals{{1,3}, {2,4}, {4,5},{6,7},{8,9}};
    show(A.merge(intervals));

    return 0;
}
