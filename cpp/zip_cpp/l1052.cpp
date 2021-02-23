#include "../tool/helper.cpp"
using namespace std;

/*
description:
1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
*/

//Class Solution
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        //customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
        int val = 0;
        for (int i = 0; i < X; ++i)
        {
            val += customers[i];
        }
        int ret = val;
        for (int i = X; i < customers.size(); ++i)
        {
            val += customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X];
            cout << "i:" << i << " val:" << val << " ret:" << ret << endl;
            ret = max(ret, val);
        }

        return ret;
    }
};

int main()
{
    Solution A;
    vector<int> customers{1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy{0, 1, 0, 1, 0, 1, 0, 1};
    cout << A.maxSatisfied(customers, grumpy, 3) << endl;

    return 0;
}
