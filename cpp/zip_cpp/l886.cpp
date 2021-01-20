#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> num;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        n = dislikes.size();
        for(int i =0; i<n; ++i)
        {
            for(int j=0; j<dislikes[i].size(); ++j)
            {
                int b = dislikes[i][j] - 1;
                num[i][b] = 1;
            }
        }
        for(int i=0; i<n; ++i)
        {
            if()
        }
    }
    bool dfs(i, )
    {
        color[i] = thecolor;
        for (int i=0;i<n;++i)
        {
            if(color[i] !=0)
        }
    }
};


int main()
{
    Solution A;    

    return 0;
}
