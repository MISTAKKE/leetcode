#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
1 <= n <= 9
1 <= k <= n!

*/

// Class Solution
class Solution {
  public:
    string getPermutation(int n, int k) {
        k -= 1;
        vector<int> idx;
        int maxsub = 1;
        for(int i = 1;i<n;++i){
            maxsub *= i;
        }
        int i = n - 1;
        while (maxsub >= 1 && i > 0) {
            // cout << "k:" << k << " maxsub:" << maxsub <<" si:"<<i<< endl;
            idx.push_back(k / maxsub);
            k = k % maxsub;
            maxsub = maxsub / i;
            i -= 1;
        }
        show(idx);

        // 1234567
        string ret = "";
        for (int i = 1; i <= n; ++i) {
            ret += ('0' + i);
        }
        for (int i = 0; i < idx.size(); ++i) {
            if (idx[i] > 0) {
                // cout << "i:" << i << " idx[i]:" << idx[i] << endl;
                for (int j = 0; j < idx[i]; ++j)  // 0 1 2
                {
                    // cout << "swap: " << ret[i + idx[i]] << " " << ret[i + j] << endl;
                    swap(ret[i + idx[i]], ret[i + j]);
                }
            }
        }
        return ret;
    }
};

// Class Solution
class Solution2 {
  public:
    string getPermutation(int n, int k) {
        k -= 1;
        // n=7  k = 4! + 4! + 4! + 3! + 2! + 1
        vector<int> interval{362880, 40320, 5040, 720, 120, 24, 6, 2, 1};
        vector<int> idx{0, 0, 0, 0, 0, 0, 0, 0, 0};
        int start = 0;
        // k = 4! + 4! + 4! + 3! + 2!
        while (k != 0) {
            idx[start] = k / interval[start];
            k = k % interval[start];
            start += 1;
        }
        // idx = {0,0,0, 0,3,1, 1,0,0};
        // show(idx);

        // 1234567
        string ret = "";
        for (int i = 1; i <= n; ++i) {
            ret += ('0' + i);
        }
        for (int i = 0; i <= 9; ++i) {
            // i = 5 idx[4]=3
            // i = 6 idx[6]=1
            if (idx[i] > 0) {
                cout << "i:" << i << " idx[i]:" << idx[i] << endl;
                // i    0 1 2 3 4 5 6
                // idx  0 0 0 0 0 3 1
                //      1 2 3 4 5 6 7
                //  4-> 1 2 6 3 4 5 7
                //  3-> 1 2 6 4 3 5 7
                //  2-> 1 2 6 4 5 3 7
                for (int j = 0; j < idx[i]; ++j)  // 0 1 2
                {
                    cout << "swap: " << ret[n - idx.size() + i - 1 + idx[i]] << "   " << ret[n - idx.size() + i - 1 + j]
                         << endl;
                    swap(ret[n - idx.size() + i - 1 + idx[i]], ret[n - idx.size() - 1 + i + j]);
                }
            }
        }
        return ret;
    }
};
int main() {
    Solution A;
    cout << A.getPermutation(3, 2) << endl;
    return 0;
}
