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
        map<int,int>parent;
        for(auto &&p : vec)
        {
            int &a = p[0];
            int &b = p[1];
            if(a!=-1 && parent.find(a) == parent.end())
            {
                parent[a] = a;
            }
            if(b!=-1 && parent.find(b) == parent.end())
            {
                parent[b] = b;
            }
            //try merge
            if(a !=-1 && b!= -1)
            {
                merge(parent, a, b);
            }
        }

        //get cnt
        map<int, vector<int>> res;
        for(auto &p : parent)
        {
            if(p->first != p->second)
            {
                if(res.find(p->second) == res.end())
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
    int find(map<int,int> &parent, int idx)
    {
        return idx==parent[idx] ? idx : parent[idx]=find(parent, parent[idx]);
        int tmp = idx;
        while(parent[idx] !=idx)
        {
            idx = parent[idx];
        }
        while(tmp != idx)
        {
            int t = parent[tmp];
            parent[tmp] = idx;
            tmp = t;
        }
        return idx;
    }
    void merge(map<int,int> &parent, int i, int j)
    {
        i = find(parent, i);
        j = find(parent, j);
        parent[i] = j;
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
