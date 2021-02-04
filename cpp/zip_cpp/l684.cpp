#include "../tool/helper.cpp"
using namespace std;

/*
description:
思路：每条边加入前判断是否同根，如果是则返回；如果不是则加入

*/

//Class Solution
class Solution {
public:
    vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i =1; i<=n; ++i)
        {
            parent[i] = i;
        }
        for(auto p: edges)
        {
            show(p);
            show(parent);
            if(find(p[0]) == find(p[1]))
            {
                return {p};
            }
            merge(p[0], p[1]);
        }
        return parent;
    }
    int find(int idx)
    {
        while(idx != parent[idx])
            idx = parent[idx];
        return idx;
    }
    void merge(int i, int j)
    {
        i = find(i);
        j = find(j);
        parent[i] = j;
    }
};


int main()
{
    Solution A;
    //cvector<vector<int> > vec{{1,2}, {1,3}, {2,3}};
    //vector<vector<int> > vec{{1,2}, {2,3}, {3,4}, {1,4}, {1,4}};
    vector<vector<int> > vec{{1,4}, {3,4}, {1,3}, {1,2}, {4,5}};
    show(A.findRedundantConnection(vec));

    return 0;
}
