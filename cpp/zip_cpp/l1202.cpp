#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s 中只含有小写英文字母

*/

// Class Solution

class Solution {
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> father;
        for (int i = 0; i < n; ++i) {
            father.push_back(i);
        }
        for (int i = 0; i < pairs.size(); ++i) {
            merge(father, pairs[i][0], pairs[i][1]);
        }
        map<int, set<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[find(father, i)].insert(s[i] * 100000 + i);
        }
        std::string ret{""};
        for (int i = 0; i < n; ++i) {
            auto it = mp[father[i]].begin();
            ret += char(*it / 100000);
            mp[father[i]].erase(it);
        }
        return ret;
    }
    int find(vector<int>& father, int i) {
        int f = i;
        while (i != father[i]) {
            i = father[i];
        }
        while (f != i) {
            int tmp = father[f];
            father[f] = i;
            f = tmp;
        }
        return i;
    }
    void merge(vector<int>& father, int i, int j) {
        father[find(father, i)] = find(father, j);
    }
};

int main() {
    Solution A;
    string s = "pwqlmqm";
    vector<vector<int>> vec{{5, 3}, {3, 0}, {5, 1}, {1, 1}, {1, 5}, {3, 0}, {0, 2}};
    cout << A.smallestStringWithSwaps(s, vec) << endl;
    return 0;
}

// lpqwmqm
// lpqqmwm
