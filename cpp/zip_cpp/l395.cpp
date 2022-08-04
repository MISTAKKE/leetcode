#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int gap;
    string str;
    int longestSubstring(string s, int k) {
        gap = k;
        str = s;
        return helper(0, s.size());
    }
    int helper(int start, int end) {
        vector<int> vec(26, 0);
        for (int i = start; i < end; ++i) {
            vec[str[i] - 'a']++;
        }
        int idx = start;
        while (idx < end && vec[str[idx] - 'a'] >= gap)
            idx++;
        if (idx == end)
            return end - start;
        int maxval = helper(start, idx);
        while (idx < end && vec[str[idx] - 'a'] < gap)
            idx++;
        if (idx != end)
            maxval = max(maxval, helper(idx, end));
        return maxval;
    }
};

class Solution2 {
  public:
    int longestSubstring(string s, int k) {
        if (k <= 1)
            return s.size();
        if (s.empty() || s.size() < k)
            return 0;

        vector<int> hash(128, 0);
        for (char c : s)
            ++hash[c];

        int i = 0;
        while (i < s.size() && hash[s[i]] >= k)
            ++i;
        if (i == s.size())
            return s.size();

        int l = longestSubstring(s.substr(0, i), k);
        while (i < s.size() && hash[s[i]] < k)
            ++i;
        int r = longestSubstring(s.substr(i), k);

        return max(l, r);
    }
};

int main() {
    Solution A;
    string str = "ababbc";
    cout << A.longestSubstring(str, 2) << endl;
    return 0;
}
