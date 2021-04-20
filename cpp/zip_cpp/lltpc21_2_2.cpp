#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;//n组case
    vector<vector<int>> vec;//每一组case的数组  每一组有3个数
    vector<int> res;//结果
    for (int i = 0; i < n; ++i)
    {
        vector<int> vec2;
        cin >> a;
        cin >> b;
        cin >> c;
        vec2.push_back(a);
        vec2.push_back(b);
        vec2.push_back(c);
        vec.push_back(vec2);
    }

    for (int i = 0; i < n; ++i)
    {
        unsigned long before_a1 = 1;
        unsigned long before_b1 = 0;

        unsigned long last_a1 = 0;
        unsigned long last_b1 = 1;

        int cnt = vec[i][0] - 1;
        int A = vec[i][1];
        int B = vec[i][2];
        unsigned long x = A | B;

        vector<bool> vecbool(1000000, false);
        int maxnow = 0;
        int now = 0;
        while(x!=0)
        {
            if(x%2!=0)
                vecbool[now] = true;
            if(now > maxnow)
                maxnow = now;
            now +=1;
            x = x/2;
        }

        while(cnt--)
        {
            int temp_a = last_a1 + before_a1;
            int temp_b = last_b1 + before_b1;

            before_a1 = last_a1;
            before_b1 = last_b1;

            last_a1 = temp_a;
            last_b1 = temp_b;
            
            unsigned long y = A * temp_a + B * temp_b;
            // cout<<"y:"<<y<<endl;
            now = 0;
            while(y!=0)
            {
                if(y%2!=0 && !vecbool[now])
                    vecbool[now] = true;
                if(now > maxnow)
                    maxnow = now;
                now +=1;
                y = y/2;
            }
        }

        int zero = 0;
        for(int ii = 0; ii<=maxnow; ++ii)
        {
            if(!vecbool[ii])
                zero += 1;
        }
        res.push_back(zero);
    }
    for (unsigned int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << endl;
    }

    return 0;
}

