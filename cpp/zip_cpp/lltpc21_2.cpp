#include <algorithm>
#include <iostream>
#include <vector>
#include "../tool/helper.cpp"
using namespace std;

int main()
{
    // int n, a, b;
    // cin >> n;
    // vector<vector<int>> vec;
    // for (int i = 0; i < n; ++i)
    // {
    //     vector<int> vec2;
    //     cin >> a;

    //     for (int j = 0; j < a; ++j)
    //     {
    //         cin >> b;
    //         vec2.push_back(b);
    //     }
    //     vec.push_back(vec2);
    // }
    int n = 1;
    vector<vector<int>> vec{{3,4,5}};
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        vector<int> &p = vec[i];
        int cnt = 0;
        sort(p.begin(), p.end());
        // show(p);
        for (size_t j = 0; j < p.size(); ++j)
        {
            cout << endl << "p[j]:" << p[j] << endl;
            for (int k = 1; k < p[j]; ++k)
            {
                cout << "p[j] - k:" << p[j] - k << endl;
                if (find(p.begin(), p.begin() + j + 1, p[j] - k) == p.begin() + j + 1)
                {
                    if (find(p.begin(), p.begin() + j + 1, k) == p.begin() + j + 1)
                    {
                        if (p[j] - k != k)
                        {
                            cout<<"got it:   p[j]-k:"<<p[j]-k<<" k:"<<k<<endl;
                            cnt += 1;
                            break;
                        }
                    }
                }
            }
        }
        res.push_back(cnt);
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
