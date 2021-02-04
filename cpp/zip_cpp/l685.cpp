#include "../tool/helper.cpp"
using namespace std;

/*
description:
思路:
case1 边在加入并查集的时候无法加入，那么问题就是这条边

case2 存在有两条边指向同一个节点
    1 先判断尾巴节点有没有被加过，如果有就待定，有两条边指向同一个节点，问题只能出现在这两条边中
    2 把其他的边加入并查集；如果加不进去则是问题边（case1）
    3 把这两条边加入并查集，如果加不进去则是问题边

*/

//Class Solution
class Solution {
public:
    vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        vector<int> mark;
        int va, vb;
        for(int i =0; i<n; ++i)
        {
            int start = edges[i][0];
            int end = edges[i][1];
            if(parent[end] != 0)
            {
                
                va = edges[parent[end]-1][0]* 10000 + edges[parent[end]-1][1];
                vb = edges[i][0] * 10000 + edges[i][1];
            }
            parent[end] = i+1;
        }
        for(int i =1; i<=n; ++i)
        {
            parent[i] = i;
        }
        for(auto p: edges)
        {
            int val = p[0] * 10000 + p[1];
            if(val !=va && val !=vb)
            {
                if(find(p[0] == find(p[1])))
                    return {p};
                merge(p[0], p[1]);
            }                
        }
        int ax = va / 10000;
        int ay = va % 10000;
        if(find(ax) == find(ay))
        {
            return {ax, ay};
        }
        else
        {
            return {vb/10000, vb%10000};
        }
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
    //vector<vector<int> > vec{{1,2}, {2,3}, {1,3}};
    //vector<vector<int> > vec{{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
    //vector<vector<int> > vec{{1,4}, {3,4}, {1,3}, {1,2}, {4,5}};
    vector<vector<int> > vec{{2,1}, {3,1}, {4,2}, {1,4}};
    show(A.findRedundantConnection(vec));

    return 0;
}
