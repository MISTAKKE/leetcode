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
        map<int, int> father;
        map<int, int> fathercnt;
        int maxcnt{0};
        map<int, set<int>> primedata;
        for (auto& c : nums) {
            getprime(primedata, c);
        }
        for (auto& it : primedata) {
            auto c = it.first;
            if (c == 1) {
                continue;
            }
            for (auto& d : it.second) {
                if (find(father, c) != find(father, d))
                    merge(father, c, d);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            int d = find(father, nums[i]);
            fathercnt[d] += 1;
            maxcnt = max(maxcnt, fathercnt[d]);
        }
        return maxcnt;
    }
    void getprime(map<int, set<int>>& primedata, int n) {
        int original = n;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                n = n / i;
                while (n % i == 0) {
                    n = n / i;
                }
                primedata[i].insert(original);
            }
        }
        primedata[n].insert(original);
    }
    int find(map<int, int>& father, int i) {
        if (father.end() == father.find(i)) {
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
    void merge(map<int, int>& father, int i, int j) {
        father[find(father, i)] = find(father, j);
    }
};
int main() {
    Solution A;
    vector<int> vec{2, 3, 6, 7, 4, 12, 21, 39};
    cout << A.largestComponentSize(vec) << endl;

    return 0;
}
