#include "../tool/helper.cpp"
using namespace std;

/*
description:
提示：

1 <= strs.length <= 100
1 <= strs[i].length <= 1000
sum(strs[i].length) <= 2 * 104
strs[i] 只包含小写字母。
strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。

*/

// Class Solution
class Solution {
  public:
    int len;
    int n;
    vector<int> parent;
    int find(int idx) {
        return idx == parent[idx] ? idx : parent[idx] = find(parent[idx]);
    }
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        if (n <= 1)
            return n;
        len = strs[0].size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        show(parent);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int pi = find(i);
                int pj = find(j);
                if (pi != pj && issame(strs[i], strs[j])) {
                    parent[pi] = pj;
                }
            }
        }
        show(parent);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i)
                ret += 1;
        }
        return ret;
    }
    bool issame(const string& a, const string& b) {
        int diffcnt = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                diffcnt++;
                if (diffcnt > 2)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution A;
    vector<string> str{"zkhnmefhyr", "ykznfhehmr", "mkhnyefrzh", "zkhnyefrmh", "zkmnhefhyr",
                       "ykznhfehmr", "zkynhfehmr", "mkhnhefrzy", "zkhnmefryh", "zkmnhfehyr"};
    cout << A.numSimilarGroups(str) << endl;
    return 0;
}
