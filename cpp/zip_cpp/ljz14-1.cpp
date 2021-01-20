#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
     vector<vector<int>> memo;
     vector<int> dp;
     int cuttingRope(int n)
     {
        if(n<4) return n-1;
        for(int i=0;i<=n;++i)
            dp.push_back(0);
        dp[1] =1;
        dp[2] =2;
        dp[3] =3;
        dp[4] =4;
        return f(n);
     }
     int f(int n)
     {
         if(dp[n]!=0) return dp[n];
         for(int i = 2; i<= n/2; ++i)
         {
            dp[n] = max(dp[n], f(i)*f(n-i));
         }
         return dp[n];
     }
     int cuttingRope2(int n) {
         if(n<4) return n-1;
         for(int i=0;i<=n;++i)
            memo.push_back(vector<int>(n+1, -1));
         return helper(0, n);
     }

     int helper(int i, int j)
     {
         if(memo[i][j] != -1)
             return memo[i][j];

         memo[i][j] = j - i;

         for(int k = i+1; k<j; k++)
             memo[i][j] = max(memo[i][j], helper(i, k) * helper(k, j));

         return memo[i][j];
     }
};

int main()
{
    Solution A;
    cout<<A.cuttingRope(18);
    return 0;
    for(int i =1;i<100;++i)
    {
        Solution A;    
        int a = A.cuttingRope(i);
        int b = A.cuttingRope2(i);
        if(a!=b)
            cout<<"i:"<<i<<" a:"<<a<<" b:"<<b<<endl;
    }

    return 0;
}
