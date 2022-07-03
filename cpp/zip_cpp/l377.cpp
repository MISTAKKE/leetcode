#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int combinationSum4(vector<int>& candidates, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto c : candidates) {
                if (i - c >= 0 && i - c <= target) {
                    dp[i] += dp[i - c];
                }
            }
        }
        show(dp);
        return dp[target];
    }
    int combinationSum41(vector<int>& candidates, int target) {
        int ans;
        vector<int> nowval;
        dfs(candidates, ans, target);
        return ans;
    }
    void dfs(vector<int>& candidates, int& ans, int& target) {
        if (target == 0) {
            ans += 1;
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                target -= candidates[i];
                dfs(candidates, ans, target);
                target += candidates[i];
            }
        }
    }
    void dfs1(vector<int>& candidates, int target, int& ans, vector<int>& nowval) {
        if (target == 0) {
            show(nowval);
            ans += 1;
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                nowval.push_back(candidates[i]);
                dfs1(candidates, target - candidates[i], ans, nowval);
                nowval.pop_back();
            }
        }
    }
};

int main() {
    Solution A;
    vector<int> candidates{1, 2, 3};
    int target = 4;
    cout << A.combinationSum4(candidates, target) << endl;

    return 0;
}
