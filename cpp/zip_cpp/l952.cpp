#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^5
nums 中所有值都 不同

*/

// Class Solution
class Solution {
  public:
    int largestComponentSize(vector<int>& nums) {
        vector<int> father(100000, -1);
        map<int, int> fathercnt;
        int maxcnt{0};
        map<int, set<int>> record;
        record[1] = set<int>{};
        vector<set<int>> primedata(100000, set<int>{});
        for (auto& c : nums) {
            auto ret = getprime(record, c);
            // show(ret);
            for (auto val : ret) {
                // cout << "val:" << val << " c:" << c << endl;
                primedata[val].insert(c);
            }
        }
        for (auto& it : primedata) {
            for (auto& c : it) {
                for (auto& d : it) {
                    if (c != d && find(father, c) != find(father, d))
                        merge(father, c, d);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            fathercnt[find(father, nums[i])] += 1;
            maxcnt = max(maxcnt, fathercnt[find(father, nums[i])]);
        }
        return maxcnt;
    }
    set<int> getprime(map<int, set<int>>& record, int n) {
        // cout << "getprime n:" << n << endl;
        if (record.find(n) != record.end()) {
            // cout << "find1 show record[n]:" << endl;
            // show(record[n]);
            return record[n];
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                n = n / i;
                set<int> res = getprime(record, n);
                res.insert(i);
                return res;
            }
        }
        record[n] = set<int>{n};
        return record[n];
    }
    int find(vector<int>& father, int i) {
        if (father[i] == -1) {
            father[i] = i;
            return i;
        }
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
    vector<int> vec{2, 3, 6, 7, 4, 12, 21, 39};
    cout << A.largestComponentSize(vec) << endl;

    return 0;
}
