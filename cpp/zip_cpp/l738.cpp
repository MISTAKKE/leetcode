#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        int res = N;
        int i = 1;
        while (res / i)
        {
            int n = res / i % 100;
            i *= 10;
            if (n / 10 > n % 10)
            {
                res = res / i * i - 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution A;
    cout<<A.monotoneIncreasingDigits(333332)<<endl;

    return 0;
}
