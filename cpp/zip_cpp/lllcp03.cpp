#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution
{
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y)
    {
        unordered_set<long> s;
        s.insert(0);
        long xx = 0, yy = 0;
        for (auto &c : command)
        {
            if (c == 'U')
                yy++;
            else
                xx++;
            s.insert(xx<<30 | yy);
        }
        int loop = min(x/xx, y/yy);
        if(s.count(((long)(x-loop*xx) << 30) | (y-loop*yy)) == 0)
            return false;
        for(auto &v:obstacles)
        {
            if(v[0]> x || v[1]>y) continue;
            loop = min(v[0]/xx, v[1]/yy);
            if(s.count(((long)(v[0]-loop*xx) << 30) | (v[1]-loop*yy)) == 1)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution A;

    return 0;
}
