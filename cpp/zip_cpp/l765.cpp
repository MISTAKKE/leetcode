#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution1
{
public:
    int find(vector<int> &father, int i)
    {
        int son = father[i];
        while (i != father[i])
        {
            i = father[i];
        }
        while (son != i)
        {
            int tmp = father[son];
            father[son] = i;
            son = tmp;
        }
        return i;
    }
    void merge(vector<int> &father, int i, int j)
    {
        i = find(father, i);
        j = find(father, j);
        father[i] = j;
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        vector<int> place(n, 0); //通过值找idx
        vector<int> father(n, 0);

        for (int idx = 0; idx < n; ++idx)
        {
            if (row[idx] % 2 == 1) //奇数变偶数
                row[idx] -= 1;
            else //只有偶数才设置father
                father[row[idx]] = row[idx];
        }
        for (int idx = 1; idx < n; idx += 2)
        {
            if (row[idx] != row[idx - 1])
            {
                merge(father, row[idx], row[idx - 1]); //右侧与左侧不同，则merge
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (father[i] != i) //root
                cnt += 1;
        }
        //有N=n/2对数据，M=cntok对是不需要换的； N-M=n/2-cntok对需要换，其中并查集个数为K=cnt
        //cout << "n:" << n << " cnt:" << cnt << endl;
        return cnt;
    }
};

// 2 2 0 0

// 0 3  4 1  2 7  6 9  8 5
// ---  ---  ---  ---  ---

//         每两个座位成一对，假定左边的人都是合法的不变，如果TA右边的人与TA匹配则
//         跳过，不匹配则找到TA的匹配对象的与TA右边的人交换。
class Solution
{
public:
    int parter(int val)
    {
        if (val % 2 == 0)
            return val + 1;
        return val - 1;
    }
    int minSwapsCouples(vector<int> &row)
    {
        int count = 0;
        for (int i = 0; i < row.size(); i += 2)
        {
            int p1 = row[i];
            int p2 = parter(p1); //expected
            if (p2 != row[i + 1])
            {
                int idx = find(row.begin(), row.end(), p2) - row.begin();
                row[idx] = row[i + 1];
                row[i + 1] = p2;
                count += 1;
            }
        }
        return count;
    }
};

class Solution
{
public:
    vector<int> parent;
    int find(int idx)
    {
        int father = parent[idx];
        while (idx != parent[idx])
        {
            idx = parent[idx];
        }
        while (parent[father] != idx)
        {
            int tmp = parent[father];
            parent[father] = idx;
            father = tmp;
        }
        return idx;
    }
    void merge(int i, int j)
    {
        i = parent[i];
        j = parent[j];
        if (i < j)
            parent[i] = j;
        else
            parent[j] = i;
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size() / 2;
        parent.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            int p1 = row[i * 2] / 2;
            int p2 = row[i * 2 + 1] / 2;
            merge(p1, p2);
        }
    }
};
/*
方案1 并查集
    空间复杂度 o(N)
    时间复杂度 o(N)
方案2 贪心+查找交换
    时间复杂度o(N^2)
    空间复杂度o(1)
*/
int main()
{
    Solution A;
    // vector<int> res{0, 2, 1, 3}; // 1
    // vector<int> res{0, 3, 4, 1, 2, 7, 6, 9, 8, 5}; // 4
    vector<int> res{3, 2, 0, 1}; // 0

    cout << A.minSwapsCouples(res) << endl;
    return 0;
}

// class Solution(object):
//     def minSwapsCouples(self, row):
//         """
//         每两个座位成一对，假定左边的人都是合法的不变，如果TA右边的人与TA匹配则
//         跳过，不匹配则找到TA的匹配对象的与TA右边的人交换。
//         """
//         def find_another(n):
//             if n % 2 == 0:
//                 return n + 1
//             else:
//                 return n - 1

//         c = 0
//         for i in range(0, len(row), 2):
//             p1 = row[i]
//             p2 = find_another(p1)
//             if row[i+1] != p2:
//                 j = row.index(p2)
//                 row[i+1], row[j] = row[j], row[i+1]
//                 c += 1

//         return c
