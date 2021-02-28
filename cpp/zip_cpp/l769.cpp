#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] > idx)
            {
                idx = arr[i];
            }
            else if (i == idx)
            {
                cnt += 1;
                idx = i + 1;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution A;
    //vector<int> vec{4, 3, 2, 1, 0};
    vector<int> vec{1, 0, 2, 3, 4};
    cout << A.maxChunksToSorted(vec) << endl;

    return 0;
}
