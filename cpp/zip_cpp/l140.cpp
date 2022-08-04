#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int minval = 10000;
        int maxval = 0;
        vector<unordered_set<string>> dp(s.size() + 1);  // dp[i] is from start to s[i-1] is ok
        dp[0].insert("");
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
                if (find(dict.begin(), dict.end(), str) != dict.end() && dp[i - len].size() > 0) {
                    for (auto c : dp[i - len]) {
                        dp[i].insert(c.empty() ? str : c + " " + str);
                    }
                }
            }
        }
        return vector<string>(dp[s.size()].begin(), dp[s.size()].end());
    }
};

int main() {
    Solution A;

    return 0;
}
