#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int func(int n, int m) {
        long long int res = 1;
        for (int i = n; i > n - m; --i) {
            res *= i;
        }
        for (int i = 1; i <= m; ++i) {
            res /= i;
        }
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<int, int>> mp(nums.size(), map<int, int>{});
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j];
                mp[i][d] = mp[j][d] + 1;
            }
        }
        int res = 0;
        for (auto c : mp[nums.size() - 1]) {
            int gap = c.second;
            cout << "c:" << c << " gap:" << gap << endl;
        }
        for (auto c : mp[nums.size() - 1]) {
            int gap = c.second + 1;
            cout << "gap:" << gap - 1 << endl;
            for (int k = 3; k <= gap; ++k) {  // gap个0
                res = res + func(gap, k);
            }
        }
        return res;
    }
};
int main() {
    Solution A;
    vector<int> nums{2, 4, 6, 8, 10};
    cout << A.numberOfArithmeticSlices(nums) << endl;

    return 0;
}
