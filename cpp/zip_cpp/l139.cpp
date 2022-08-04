#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
1. 使用dict制作一个字典树
2. dp[i][j]标识i到j是否可达，求dp[0][len-1]
*/

// Class Solution
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int minval = 10000;
        int maxval = 0;
        vector<bool> dp(s.size() + 1, false);  // dp[i] is from start to s[i-1] is ok
        dp[0] = true;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (wordDict[i].size() > maxval)
                maxval = wordDict[i].size();
            if (wordDict[i].size() < minval)
                minval = wordDict[i].size();
        }
        for (int i = minval; i <= s.size(); ++i)  // find out if dp[i] is ok
        {
            // from s[i]  len is minval to maxval
            for (int len = minval; len <= maxval && i - len >= 0; ++len) {
                string str = s.substr(i - len, len);
                if (find(dict.begin(), dict.end(), str) != dict.end() && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution A;
    string s = "applepen";
    vector<string> wordDict{"apple", "pen"};
    cout << A.wordBreak(s, wordDict);

    return 0;
}
