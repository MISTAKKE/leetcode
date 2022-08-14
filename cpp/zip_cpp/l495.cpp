#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = duration;
        int end = duration + timeSeries[0];
        for (int i = 1; i < timeSeries.size(); ++i) {
            res += duration;
            res -= max(0, end - timeSeries[i]);
            end = duration + timeSeries[i];
        }
        return res;
    }
};
int main() {
    Solution A;
    vector<int> timeSeries{1, 4, 5, 6, 8};
    cout << A.findPoisonedDuration(timeSeries, 2);

    return 0;
}
