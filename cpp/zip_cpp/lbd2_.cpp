#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<vector<int>> output(vector<vector<int>> &vec)
    {
        vector<vector<int>> ret;
        map<int,int>father;
        for(auto &&p : vec)
        {
            int &a = p[0];
            int &b = p[1];
            if(a!=-1 && father.find(a) == father.end())
            {
                father[a] = a;
            }
            if(b!=-1 && father.find(b) == father.end())
            {
                father[b] = b;
            }
            //try merge
            if(a !=-1 && b!= -1)
            {
                merge(father, a, b);
            }
        }

        //get cnt
        map<int, vector<int>> res;
        for(auto &p : father)
        {
            if(p->first != p->second)
            {
                if(father.find(p->second) == father.end()
                    res[p->second] = vector<int>();
                res[p->second].push_back(p->first);
            }
        }

        //get res
        for(auto &p : res)
        {
            ret.push_back(vector<int>());
            int &root = p->first;
            vector<int> &val = p->second;
            for (auto &i : val)
                ret.back().push_back(i);
            ret.back().push_back(root);
        }

        return ret;
    }
    int find(map<int,int> &father, int idx)
    {
        int tmp = idx;
        while(father[idx] !=idx)
        {
            idx = father[idx];
        }
        while(tmp != idx)
        {
            int t = father[tmp];
            father[tmp] = idx;
            tmp = t;
        }
        return idx;
    }
    void merge(map<int,int> &father, int i, int j)
    {
        i = find(father, i);
        j = find(father, j);
        father[i] = j;
    }
    
};






智慧高速
1 路面检测，CV，交通事件
2 视频监控，基础设施
target：车脸识别
20 人 * 2



int main()
{
    Solution A;

    return 0;
}
