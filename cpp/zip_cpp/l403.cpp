#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true;  //此处的0代表着，他后续只能跳 -1 0 1步
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int gap = stones[i] - stones[j];
                // i=1 j=0 gap=0
                dp[i][gap] = dp[j][gap - 1] || dp[j][gap] || dp[j][gap + 1];
                if (dp[n - 1][gap]) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
  public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            //在点i处 是跳k步过来的
            for (int k = 0; k <= i + 1; ++k) {
                //在第i个石头上 并且上次通过k步跳过来 （现在可以从此处跳下一个地方 并且可以有三个机会）
                if (dp[i][k]) {
                    //粗略的地方 idx 是第一个大于等于 stones[i]+k 的下标
                    int idx = lower_bound(stones.begin(), stones.end(), stones[i] + k) - stones.begin();
                    // cout << "i:" << i << " k:" << k << " idx:" << idx << " stones[i]:" << stones[i]
                    //      << " stones[k]:" << stones[k] << endl;
                    // k-1步
                    if (k - 1 > 0 && stones[i] + k - 1 == stones[idx - 1]) {
                        dp[idx - 1][k - 1] = true;
                    }
                    // k步
                    if (idx < n && stones[i] + k == stones[idx]) {
                        dp[idx][k] = true;
                    }
                    // k+1步
                    if (idx < n && stones[i] + k + 1 == stones[idx]) {
                        dp[idx][k + 1] = true;
                    }
                    // k+1步
                    if (idx + 1 < n && stones[i] + k + 1 == stones[idx + 1]) {
                        dp[idx + 1][k + 1] = true;
                    }
                }
            }
        }
        // stones.insert(stones.begin(), 0);
        // show(stones);
        // show(dp);
        for (int i = 0; i < dp[n - 1].size(); ++i) {
            if (dp[n - 1][i]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution A;
    // vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};  // 1
    // vector<int> stones{0, 2};  // 0
    vector<int> stones{0, 1, 2, 3, 4, 8, 9, 11};  // 0
    cout << A.canCross(stones) << endl;
    return 0;
}
