#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nowval;
        dfs(candidates, target, ans, nowval, 0);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& nowval, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.push_back(nowval);
            return;
        }
        //跳过当前值
        dfs(candidates, target, ans, nowval, idx + 1);
        //包括当前值
        if (target - candidates[idx] >= 0) {
            nowval.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, nowval, idx);
            nowval.pop_back();
        }
    }
};
class Solution2 {
  public:
    bool issame(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != v2.size())
            return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // dp[i] 标识总合为dp[i]时的组合集合
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>{});
        for (int i = 0; i < candidates.size(); ++i) {
            int val = candidates[i];
            if (val <= target) {
                dp[val].push_back(vector<int>{val});
            }
        }
        for (int i = 2; i <= target; ++i) {
            for (int k = 1; ((k * 2 - 1) < i); ++k) {
                if (dp[k].size() > 0 && dp[i - k].size() > 0) {
                    // cout << "i:" << i << " k:" << k << " i-k:" << i - k << endl;
                    for (int d1 = 0; d1 < dp[k].size(); ++d1) {
                        for (int d2 = 0; d2 < dp[i - k].size(); ++d2) {
                            // cout << "i:" << i << " i-k:" << i - k << " d1:" << d1 << " d2:" << d2 << endl;
                            vector<int> valsum = dp[k][d1];
                            valsum.insert(valsum.end(), dp[i - k][d2].begin(), dp[i - k][d2].end());
                            sort(valsum.begin(), valsum.end());
                            // cout << "valsum:" << endl;
                            // show(valsum);
                            bool ispass = false;
                            for (int now = 0; now < dp[i].size(); now++) {
                                if (issame(valsum, dp[i][now])) {
                                    ispass = true;
                                    break;
                                }
                            }
                            if (!ispass) {
                                dp[i].push_back(valsum);
                            }
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < dp.size(); ++i) {
        //     cout << "i: " << i << " dp[i]:" << endl;
        //     show(dp[i]);
        // }
        return dp[target];
    }
};
int main() {
    Solution A;
    vector<int> candidates{2, 3, 5};
    int target = 8;
    show(A.combinationSum(candidates, target));
    return 0;
}
