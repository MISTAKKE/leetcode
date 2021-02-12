#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
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

int main()
{
    Solution A;
    vector<int> res{0, 2, 1, 3}; // 1
    //vector<int> res{0, 3, 4, 1, 2, 7, 6, 9, 8, 5}; // 4
    //vector<int> res{3, 2, 0, 1}; // 0

    cout << A.minSwapsCouples(res) << endl;
    return 0;
}
