#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int count(int val, int& nowval) {
        // a是位数
        // m是最高位的值(不可能为0)
        int a = 11, m = 0, valtmp = val;
        while (m == 0) {
            a = a - 1;
            m = valtmp / pow(10, a - 1);
            nowval = m * pow(10, a - 1);
        }
        // cout << "a:" << a << " m:" << m << endl;
        if (a <= 1) {
            // cout << "val:" << val << " res:1" << endl;
            return 1;
        }
        int res = pow(10, a - 2) * (a - 1) * m;
        if (m == 1) {
            int valleft = val - pow(10, a - 1) + 1;
            res = res + valleft;
        }
        else {
            res = res + pow(10, a - 1);
        }
        // cout << "val:" << val << " res:" << res << endl;
        return res;
    }
    int countDigitOne(int n) {
        int res = 0;
        int nowval = 0;
        int time = pow(10, 9);
        while (n != 0) {
            res += count(n, nowval);
            int m = n / time;
            n = n - nowval;
        }
        return res;
    }
};

int main() {
    Solution A;
    // int last = 0;
    // for (int i = 0; i < 1000; ++i) {
    //     int now = A.countDigitOne(i);
    //     if (now < last) {
    //         cout << "i:" << i << " last:" << last << " now:" << now << endl;
    //     }
    //     else {
    //         cout << "i:" << i << " now:" << now << endl;
    //     }
    // }
    cout << A.countDigitOne(1000) << endl;

    return 0;
}
