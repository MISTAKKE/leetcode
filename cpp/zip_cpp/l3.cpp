#include "../tool/helper.cpp"
using namespace std;

/*
description:

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成
*/

// Class Solution
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        map<int, int> mp;
        mp[s[0]] = 0;
        int start = 0;
        int maxval = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (mp.find(s[i]) != mp.end()) {
                // s[i] in mp 结算之前的值
                // cout << "i:" << i << " start:" << start << " mp[s[i]]:" << mp[s[i]] << endl;
                maxval = max(maxval, i - start);
                // 修改开头为当前值的下一个
                start = max(start, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
        }
        // cout << "s.size():" << s.size() << " start:" << start << endl;
        maxval = max(maxval, int(s.size()) - start);
        return maxval;
    }
};
class Solution2 {
  public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, -1);
        int maxval = 0;
        for (int i = 0; i < s.size(); ++i) {
            int idx = vec[s[i]];
            if (idx != -1)  // exist in vec
            {
                int val = 0;
                for (int k = 0; k < 256; ++k) {
                    if (vec[k] != -1) {
                        val += 1;
                        if (vec[k] <= idx) {
                            vec[k] = -1;
                        }
                    }
                }
                maxval = max(maxval, val);
            }
            vec[s[i]] = i;
        }
        int val = 0;
        for (int i = 0; i < 256; ++i) {
            if (vec[i] != -1) {
                val += 1;
            }
        }
        return max(maxval, val);
    }
};

int main() {
    Solution A;
    string s = "abcafghabd";
    cout << A.lengthOfLongestSubstring(s) << endl;

    return 0;
}
