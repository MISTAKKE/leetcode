#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        queue<int> q; //q.size() 当前节点被影响的次数   q.front() 最早影响的i
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (q.size() > 0 && q.front() + K - 1 < i)
            {
                //out
                q.pop();
            }

            if ((q.size() + A[i]) % 2 == 0)
            {
                //error
                if (i + K > A.size())
                {
                    return -1;
                }
                //in
                q.push(i);
                cnt += 1;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution A;
    vector<int> vec{0,0,0,1,0,1,1,0};
    cout << A.minKBitFlips(vec, 3) << endl;

    return 0;
}
