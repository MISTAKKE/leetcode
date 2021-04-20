#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;//n组case
    vector<vector<int>> vec;//每一组case的数组
    vector<string> res;//结果
    for (int i = 0; i < n; ++i)
    {
        vector<int> vec2;
        cin >> a;//第i组case，有多少个数
        for (int j = 0; j < a; ++j)
        {
            cin >> b;
            vec2.push_back(b);
        }
        vec.push_back(vec2);
    }
    for (int i = 0; i < n; ++i)
    {
        if(vec[i].size() % 2 == 1)
        {
            res.push_back("Yes");
            continue;
        }
        vector<int> vec1;
        vector<int> vec2;
        for(unsigned int j = 0; j<vec[i].size(); j+=2)
        {
            vec1.push_back(vec[i][j]);
            vec2.push_back(vec[i][j+1]);
        }
        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());
        bool flag = false;
        for(unsigned int j = 0; j<vec1.size(); ++j)
        {
            if((vec1[j] > vec2[j] || (j!=0 && (vec2[j-1] >vec1[j])))
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            res.push_back("No");
        }
        else
        {
            res.push_back("Yes");
        }
    }
    for (unsigned int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << endl;
    }

    return 0;
}

