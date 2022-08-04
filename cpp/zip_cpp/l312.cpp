#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            dp.push_back(vector<int>(n, 0));
        return helper(0, n - 1, nums);
    }

    int helper(int i, int j, vector<int>& nums) {
        if (dp[i][j] != 0)
            return dp[i][j];
        if (i == j)
            return nums[i];
        for (int k = i; k <= j; ++k) {
            int left = 1, right = 1;
            if (k != i)
                left = nums[k - 1];
            if (k != j)
                right = nums[k + 1];
            int ans = nums[k] * left * right;
            int res1 = 0, res2 = 0;
            if (k > i)
                res1 = helper(i, k - 1, nums);
            if (k < j)
                res2 = helper(k + 1, j, nums);
            dp[i][j] = max(dp[i][j], res1 + res2 + ans);
        }
        return dp[i][j];
    }
};

int main() {
    Solution A;
    vector<int> nums{3, 5, 8};
    cout << A.maxCoins(nums);
    return 0;
}
