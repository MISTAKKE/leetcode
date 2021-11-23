#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    vector<int> ret;
    int maxval;
    vector<int> lexicalOrder(int n)
    {
        maxval = n;
        for(int i =1;i<10;++i)
            dfs(i);
        return ret;
    }
    void dfs(int n)
    {
        if(n>maxval) return;
        ret.push_back(n);
        for(int i =0;i<10;++i)
            dfs(n*10+i);
    }
};

int main()
{
    Solution A;
    show(A.lexicalOrder(13));

    return 0;
}
