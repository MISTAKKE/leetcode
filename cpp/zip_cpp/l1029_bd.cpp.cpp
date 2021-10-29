#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

//二叉树最长路径
class TreeNode
{
    TreeNode *left;
    TreeNode *right
    int val;
    TreeNode(int v)
    {
        left=NULL;
        right=NULL;
        val =v;
    }
};

class Solution1
{
public:
    int findmax(TreeNode *r)
    {
        findlength(r);
        return maxval;
    }
private:
    int maxval{0};
    map<TreeNode, int> mp;//每个节点单向最长长度
    void findlength(TrdeNode *r)
    {
        if(r==NULL) return 0;
        if(mp.find(r)!=mp.end())
            return mp[r];
        int l1 = findlength(r->left);
        int l2 = findlength(r->right);
        mp[r->left] = l1;
        mp[r->right] = l2;
        mp[r] = max(l1, l2)+1;
        maxval = max(maxval, l1 + l2 + 1);
    }
};

//N*M的岛屿 连续岛屿的个数
class Solution2
{
public:
    int findcnt(const vector<vector<bool>> &num )
    {
        if(num.size() ==0 || num[0].size() == 0)
            return 0;
        for(int i = 0;i<num.size() * num[0].size();++i)
            parent.push_back(i);//将根节点设置为自己
        for(int i = 0;i<num.size(); ++i)
        {
            for (int j =0;j<num[0].size() ++j)
            {
                if(num[i][j])
                {
                    if(j+1<num[0].size() && num[i][j+1])
                    {
                        merge(i*num[0].size() + j, i*num[0].size() + j+1);
                    }
                    if(i+1<num.size() &&num[i+1][j])
                    {
                        merge(i*num[0].size()+j, (i+1)*num[0].size()+j);
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0;i<parent.size(); ++i)
        {
            if(parent[i] == i)
                ret+=1;
        }
        return ret;
    }
private:
    int findparent(int v)
    {
        int old = v;//保留原始节点
        while(parent[v] != v)
        {
            v = parent[v];//v是根节点
        }
        
        while(old != v)//路径压缩
        {
            int tmp = parent[old];
            parent[old] = v;
            old = tmp;
        }
        return v;
    }
    void merge(int i, int j)
    {
        int i = findparent(i);
        int j = findparent(j);
        if(i<j)
            parent[i] = j;
        else
            parent[j] = i;
    }
    vector<int>parent;
}

//高并发的lru cache


int main()
{
    Solution A;


    return 0;
}
