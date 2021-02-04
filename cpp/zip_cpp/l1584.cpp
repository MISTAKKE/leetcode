#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Solution {
public:
    class Edge{
    public:
        int iidx;
        int jidx;
        double length;
        Edge(int _iidx, int _jidx, double _length){
            iidx = _iidx;
            jidx = _jidx;
            length = _length;
        }
        bool operator<(const Edge &b) const
        {
            return length > b.length;
        }
        //test
        void shownode() const
        {
            cout<<"iidx:"<<iidx<<" jidx:"<<jidx<<" length:"<<length<<endl;
        }
    };
    double getlength(double ix, double iy, double jx, double jy)
    {
        return abs(ix - jx)+abs(iy - jy);
    }

    vector<int> parent;
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
        parent[j] = i;
    }

    int minCostConnectPoints(vector<vector<int> >& points) {
        int n = points.size();
        int totallenth = 0;
        int mergecnt = 0;// time of merge, when cnt is n-1 that's should over
        for(int i =0; i<n; ++i)
            parent.push_back(i);
        priority_queue<Edge, vector<Edge>, less<Edge> > q;
        for(int i = 0; i< n; ++i)
        {
            for(int j = i+1; j<n; ++j)
            {
                Edge e = Edge(i, j, getlength(points[i][0], points[i][1], points[j][0], points[j][1]));
                q.push(e);
                //e.shownode();
            }
        }
        while(!q.empty() && mergecnt < n-1)//is not ok
        {
            Edge t = q.top();
            //t.shownode();
            int pi = find(t.iidx);
            int pj = find(t.jidx);
            if(pi != pj)
            {
                merge(pi, pj);
                mergecnt+=1;
                totallenth += t.length;
            }
            q.pop();
            //show(parent);
        }
        return totallenth;
    }
};

int main()
{
    Solution A;
    //vector<vector<int>> vec{{-1000000,-1000000},{1000000,1000000}};//4000000
    //vector<vector<int>> vec{{0,0},{1,1},{1,0},{-1,1}};//4
    vector<vector<int>> vec{{3,12},{-2,5},{-4,1}};
    cout<<A.minCostConnectPoints(vec)<<endl;
    return 0;
}
