#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int smallestRangeII(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int ret = A.back() - A.front();
        for (int i = 1; i < A.size(); ++i)
        {
            int minval = min(A.front() + K, A.at(i) - K);
            int maxval = max(A.back() - K, A.at(i - 1) + K);
            ret = min(ret, maxval - minval);
        }
        return ret;
    }
};


class Solution
{
public:
    int smallestRangeII(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int ret = A.back() - A.front();
        for (int i = 1; i < A.size(); ++i)
        {
            int minval = min(A.front() + K, A.at(i) - K);
            int maxval = max(A.back() - K, A.at(i - 1) + K);
            ret = max(ret, maxval - minval);
        }
        return ret;
    }
};

int main()
{
    Solution A;
    vector<int> vec{0, 10, 1};
    cout << A.smallestRangeII(vec, 2) << endl;

    return 0;
}
