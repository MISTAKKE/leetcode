#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    string ss1, ss2, ss3;
    int n1, n2, n3;
    vector<vector<int>> memo;
    bool isInterleave(string s1, string s2, string s3) {
        ss1 = s1;
        ss2 = s2;
        ss3 = s3;
        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();
        for(int i = 0; i<n1+2; ++i)
        {
            memo.push_back(vector<int>(n2+2, -1));
        }
        if(n1+n2!=n3)
            return false;
        return helper(0,0,0);
    }

    bool helper0(int i, int j, int k)
    {
        if(k==n3) return true;
        return (i!=n1 && ss1[i] == ss3[k])*helper0(i+1, j, k+1) + (j!=n2 && ss2[j] == ss3[k])*helper0(i, j+1, k+1);
    }

    bool helper(int i, int j, int k)
    {
        if(k==n3) return true;
        if(memo[i][j] != -1) return memo[i][j];
        
        if(i!=n1 && ss1[i] == ss3[k])
            memo[i+1][j] = helper(i+1, j, k+1);
        else
            memo[i+1][j] = 0;

        if(j!=n2 && ss2[j] == ss3[k])
            memo[i][j+1] = helper(i, j+1, k+1);
        else 
            memo[i][j+1] = 0;

        return memo[i+1][j] + memo[i][j+1];
    }
};

int main()
{
    Solution A;    
    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
    if(A.isInterleave(s1, s2, s3))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
