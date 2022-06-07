#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

877. 石子游戏
Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，排成一行；每堆都有 正 整数颗石子，数目为 piles[i] 。
游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。
Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束 处取走整堆石头。
这种情况一直持续到没有更多的石子堆为止，此时手中 石子最多 的玩家 获胜 。 假设 Alice 和 Bob 都发挥出最佳水平，当 Alice
赢得比赛时返回 true ，当 Bob 赢得比赛时返回 false 。

示例 1：
输入：piles = [5,3,4,5]
输出：true
解释：
Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。

示例 2：
输入：piles = [3,7]
输出：true


提示：
2 <= piles.length <= 500
piles.length 是 偶数
1 <= piles[i] <= 500
sum(piles[i]) 是 奇数
*/

// Class Solution
//一维数组
class Solution {
  public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp(piles.size(), 0);
        for (int i = 0; i < piles.size(); ++i) {
            dp[i] = piles[i];
        }
        for (int i = piles.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j <= piles.size() - 1; ++j) {
                dp[j] = max(piles[j] - dp[j - 1], piles[j - 1] - dp[j]);
            }
        }
        return dp[piles.size() - 1] > 0;
    }
};
//二维数组
class Solution2 {
  public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        for (int i = 0; i < piles.size(); ++i) {
            dp[i][i] = piles[i];
        }
        for (int i = piles.size() - 1; i >= 0; --i) {
            for (int j = piles.size() - 1; j > i; --j)
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
        return dp[0][piles.size() - 1] > 0;
    }
};
//递归
class Solution1 {
  public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        dfs(piles, dp, 0, piles.size() - 1);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return dp[0][piles.size() - 1] > sum / 2;
    }
    int dfs(vector<int>& piles, vector<vector<int>>& dp, int start, int end) {
        if (dp[start][end] > 0) {
            return dp[start][end];
        }
        if (end - start <= 1) {
            dp[start][end] = max(piles[start], piles[end]);
            return dp[start][end];
        }
        dp[start][end] =
            max(piles[start] + dfs(piles, dp, start + 1, end), piles[end] + dfs(piles, dp, start, end - 1));
        return dp[start][end];
    }
};
int main() {
    Solution A;
    vector<int> str{6, 7, 5, 10, 8, 9, 8, 9, 1, 2};
    cout << A.stoneGame(str) << endl;
    return 0;
}
