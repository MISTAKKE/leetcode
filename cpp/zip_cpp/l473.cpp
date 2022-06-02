#include "/root/leetcode/tool/helper.cpp"
using namespace std;

// Class Solution
class Solution {
  public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int n = matchsticks.size();
        int len = sum / 4;
        double a = 1;

        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); ++s) {
            for (int k = 0; k < n; ++k) {
                if ((s & (1 << k)) == 0) {
                    continue;  // i里面没有k 直接退出
                }
                int s1 = s & ~(1 << k);  //把k从i排除 记为s1
                if ((dp[s1] + matchsticks[k] <= len) && (dp[s1] >= 0)) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;  //-的优先级大于 <<
    }
};

//每个数都在 四条边 试探一次
class Solution1 {
  public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, sum / 4);
    }

    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int val) {
        //到了最后一个 都满足要求 则结束
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); ++i) {  //时间复杂度 O(4^N)  空间复杂度 O(N)栈深度
            edges[i] += matchsticks[index];
            if (edges[i] <= val && dfs(index + 1, matchsticks, edges, val)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};

int main() {
    Solution A;

    return 0;
}
