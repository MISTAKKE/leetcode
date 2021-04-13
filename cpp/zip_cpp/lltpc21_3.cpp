#include <algorithm>
#include <iostream>
#include <vector>
#include "../tool/helper.cpp"
using namespace std;
// 2
// 3 4 2 3
// 2 2
// 2 3
// D
// R
// R
// 1 1 0 2
// U
// L

// 1
// 3 4 2 3
// 2 2
// 2 3
// U
// U
// U

// 1
// 3 4 2 3
// 0 0
// 0 1
// D
// D
// D


// 'U'，'D'，'L' 和 'R'，意味着我们会将所有数字都向上，下，左或右移动一格。
int doit(vector<vector<int>> &vec2, char c)
{
    int score = 0;
    vector<vector<int>> newvec(vec2);
    if (c == 'U')
    {
        for (int j = 0; j < vec2[0].size(); ++j)
        {
            if (vec2[0][j] != -1 && vec2.size() >= 2) //not block
            {
                newvec[0][j] += vec2[1][j];
                score += vec2[1][j];
            }
        }

        for (int i = 1; i < vec2.size(); ++i)
        {
            for (int j = 0; j < vec2[0].size(); ++j)
            {
                if (vec2[i - 1][j] != -1)
                {
                    if (vec2[i][j] != -1 && i != vec2.size() - 1 && vec2[i + 1][j] != -1)
                    {
                        newvec[i][j] = vec2[i + 1][j];
                    }
                    else if(newvec[i][j] != -1)
                    {
                        newvec[i][j] = 0;
                    }
                }
                else //如果上一个是石头，那么我的值会累加
                {
                    if (i + 1 < vec2.size())
                    {
                        newvec[i][j] += vec2[i + 1][j];
                        score += vec2[i + 1][j];
                    }
                }
            }
        }
    }

    show(vec2);
    show(newvec);
    vec2 = newvec;
    return score;
}
int main()
{
    int n, a, b, c;
    cin >> n;
    vector<vector<int>> vec;
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        int len, wid, lock, pos;

        cin >> len;
        cin >> wid;
        cin >> lock;
        cin >> pos;
        vector<vector<int>> vec2(len, vector<int>(wid, 1));

        for (int j = 0; j < lock; ++j)
        {
            cin >> a;
            cin >> b;
            vec2[a][b] = -1; //-1 is block
        }
        int cnt = 0;
        for (int j = 0; j < pos; ++j)
        {
            char c;
            cin >> c;
            res.push_back(doit(vec2, c));
        }
    }
    for (size_t i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << endl;
    }

    return 0;
}

// 4
// 4
// 5 6 7 8
// 2
// 5 5
// 3
// 2 3 4
// 1
// 2

// 3
// 2
// 0
// 0
