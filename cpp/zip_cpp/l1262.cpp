#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
思路1 所有数字累加, mod = sum % 3
    case 0 那么return
    case 1 那么一定有一个奇数，或者两个偶数； 减去他们的最小值即可
    case 2 那么一定有一个偶数，或者两个奇数； 减去他们的最小值即可

思路2

*/

// Class Solution
class Solution {
  public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> val(3, 0);
        for (auto& cc : nums) {
            int a, b, c;
            a = val[0] + cc;
            b = val[1] + cc;
            c = val[2] + cc;
            val[a % 3] = max(a, val[a % 3]);
            val[b % 3] = max(b, val[b % 3]);
            val[c % 3] = max(c, val[c % 3]);
        }
        return val[0];
    }
};
class Solution1 {
  public:
    int maxSumDivThree(vector<int>& nums) {
        int sumval = 0;
        vector<vector<int>> minval(2, vector<int>(2, 10000000));
        for (auto& c : nums) {
            sumval += c;
            int mod = c % 3;
            if (mod != 0) {
                if (c < minval[mod - 1][0]) {
                    minval[mod - 1][1] = minval[mod - 1][0];
                    minval[mod - 1][0] = c;
                }
                else if (c >= minval[mod - 1][0] && c < minval[mod - 1][1]) {
                    minval[mod - 1][1] = c;
                }
            }
        }
        if (sumval % 3 == 0)
            return sumval;
        else if (sumval % 3 == 1) {  //最少有一个奇数 或 两个偶数
            if (minval[0][0] <= minval[1][0] + minval[1][1]) {
                return sumval - minval[0][0];
            }
            return sumval - minval[1][0] - minval[1][1];
        }
        else {  //至少有两个奇数 或者一个偶数
            if (minval[1][0] <= minval[0][0] + minval[0][1]) {
                return sumval - minval[1][0];
            }
            return sumval - minval[0][0] - minval[0][1];
        }
    }
};

int main() {
    Solution A;
    vector<int> vec{3, 4, 1, 2, 1, 3};
    cout << A.maxSumDivThree(vec) << endl;

    return 0;
}
