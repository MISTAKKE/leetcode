#include "../tool/helper.cpp"
using namespace std;

class Solution
{
public:
    int puzzle(int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return helper(m, n, memo);
    }

    int helper(int i, int j, vector<vector<int>> &memo)
    {
        if(memo[i][j] != -1)
            return memo[i][j];

        if(i==0 || j==0)
            return memo[i][j] = 1;

        memo[i][j] = helper(i-1, j, memo) + helper(i, j-1, memo);

        return memo[i][j];
    }
};

int main()
{
    Solution A;    
    cout<<A.puzzle(3,4);

    return 0;
}
