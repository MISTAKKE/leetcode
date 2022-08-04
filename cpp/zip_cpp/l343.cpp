#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int f(int n, vector<int>& num) {
        if (num[n] != 0)
            return num[n];
        num[n] = n;
        for (int i = 2; i <= n - 2; ++i)
            num[n] = max(num[n], f(i, num) * f(n - i, num));

        return num[n];
    }

    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        vector<int> num(60, 0);
        return f(n, num);
    }
};

int main() {
    Solution A;
    for (int i = 2; i < 11; ++i)
        print(i, A.integerBreak(i));

    return 0;
}
