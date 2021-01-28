#include "../tool/helper.cpp"
using namespace std;

/*
description:
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
*/

//Class Solution
class Cunion{
public:
    Cunion(int count){
        parent.resize(count);
        rank.resize(count);
        for(int i =0; i<count; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int idx){
        int son = idx;
        while(idx != parent[idx]){
            idx = parent[idx];
        }
        while(son != idx){
            int tmp = parent[son];
            parent[son] = idx;
            son = tmp;
        }
        return idx;
    }
    void merge(int i, int j){
        i = find(i);
        j = find(j);
        if(i == j){
            return;
        }
        else if(rank[i] == rank[j]){
            parent[i] = j;
            rank[j] += 1;
        }
        else if(rank[i]>rank[j])
        {
            parent[j] = i;
        }
        else if(rank[i]<rank[j]){
            parent[i] = j;
        }
    }
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //0 get Cunion
        Cunion c = Cunion(26);

        //1 handle merge
        for(auto i:equations){
            if(i[1] == '='){
                c.merge(i[0]-'a', i[3]-'a');
            }
        }
    
        //2 check
        for(auto i:equations){
            if(i[1] != '='){
                int p1 = c.find(i[0]-'a');
                int p2 = c.find(i[3]-'a');
                if(p1 == p2){
                    return false;
                }
            }
        }
        return true;
    }
};


int main()
{
    Solution A;
    //vector<string> vec{"q!=s","n==p","s==m","y!=h","p==s","l==t","q==p","b!=r","j==w","y!=u","a!=f","s==v","n!=a","s!=o"};
    vector<string> vec{"q!=s","n==p","s==m","p==s","q==p"};
    //vector<string> vec{"q!=s","p==s","q==p"};
    cout<<A.equationsPossible(vec)<<endl;
    return 0;
}
