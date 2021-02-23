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
        int diffval = 0;
        int postive = 0;
        for (int i = 0; i < X; ++i)
        {
            postive += customers[i] * (1 - grumpy[i]); //must add when not angry
            diffval += customers[i] * grumpy[i];       //the calmdown works only when angry
        }
        int diffmax = diffval;
        for (int i = X; i < customers.size(); ++i)
        {
            postive += customers[i] * (1 - grumpy[i]);                              //must add when not angry
            diffval += customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X]; //the calmdown works only when angry
            diffmax = max(diffmax, diffval);
        }
        return diffmax + postive;
    }
};

int main()
{
    Solution A;
    vector<int> customers{1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy{0, 1, 0, 1, 0, 1, 0, 1};
    // 1 + 1 + 1 + 1 + 7 + 5 = 16.
    // vector<int> customers{4, 10, 10};
    // vector<int> grumpy{1, 1, 0};
    cout << A.maxSatisfied(customers, grumpy, 3) << endl;

    return 0;
}
