#include "../tool/helper.cpp"
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1);
        num[0] = 1;
        num[1] = 1;
        num[2] = 2;
        num[3] = 5;
        for(int i = 4;i<=n;++i)
        {
            f(num, i, i);
        }
        return f(num, n, n);
    }
    int f(vector<int> &num, int n, int idx)
    {
        if(num[idx] != 0)
            return num[idx];
        for(int i=1; i<=n; ++i)
        {
            int val = f(num, n, i-1) * f(num, n, n-i);
            num[idx] += val;
        }
        return num[idx];
    }
};

int main()
{
    Solution A;
    for(int i = 1;i<=6;++i)
    {    
        cout<< A.numTrees(i)<<endl;
    }

    return 0;
}
