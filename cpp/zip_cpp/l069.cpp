#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int mySqrt(int x) {
        if (x == 1)
            return x;
        int min = 0;
        int max = x;
        int ans = -1;
        while (min <= max) {
            int m = (min + max) / 2;
            if (x / m < m) {
                max = m - 1;
            }
            else {
                ans = m;
                min = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution A;
    cout << A.mySqrt(4) << endl;

    return 0;
}
