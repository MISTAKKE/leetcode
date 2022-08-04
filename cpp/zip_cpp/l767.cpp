#include "../tool/helper.cpp"
using namespace std;

/*
description:
S 只包含小写字母并且长度在[1, 500]区间内。

*/

// Class Solution
#define forp(i, s, n) for (int i = (s); i < (n); i++)
class Solution {
  public:
    string reorganizeString(string S) {
        string ret;
        vector<pair<char, int>> vec(26, make_pair('a', 0));
        forp(i, 0, 26) {
            vec[i].first = 'a' + i;
        }
        for (auto c : S) {
            vec[c - 'a'].second += 1;
        }
        sort(vec.begin(), vec.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });
        int size = vec[0].second;
        if (size > (S.size() + S.size() % 2) / 2) {
            return "";
        }
        vector<string> ans(size, "");
        int l = 0;
        forp(i, 0, 26) {
            int& n = vec[i].second;
            char& c = vec[i].first;
            forp(j, 0, n) {
                ans[l++ % size].push_back(c);
            }
        }
        forp(i, 0, ans.size()) ret += (ans[i] + " ");
        return ret;
    }
};

int main() {
    Solution A;
    string str = "aab";
    cout << A.reorganizeString(str) << endl;

    return 0;
}
