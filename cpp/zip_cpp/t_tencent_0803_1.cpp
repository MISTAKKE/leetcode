#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> f()
{
    vector<int> res;
    int len;
    cin >> len;
    int score;
    cin >> score;

    int sameflag = true;
    int vallast;
    vector<int> pass;
    for(int i = 0; i<len; ++i)
    {
        int tmp;
        cin>>tmp;
        vallast = tmp;
        pass.push_back(tmp);
    }
    for(int i = 0; i<len-1; ++i)
    {
        if(vallast != pass[i])
            sameflag = false;
        pass.push_back(pass[i]);
    }

    if(sameflag)
    {
        res.push_back(score);
        res.push_back(vallast);
    }

    int maxidx = -1;
    int maxval = 0;
    for(int i = 0; i<pass.size(); ++i)
    {
        //i+1 回合数
        int each = pass[i];//当前角色id
        if(each != maxidx)
        {
            maxval = 1;
            maxidx = each;
        }
        else
        {
            maxval += 1;
        }
        if(maxval == score)
        {
            res.push_back(i+1);
            res.push_back(each);
            return res;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>res;
    while(n--)
    {
        res.push_back(f());
    }
    for(auto c:res)
    {
        if(c.size() == 0)
            cout<<"INF"<<endl;
        else
            cout<<c[0]<<" "<<c[1]<<endl;
    }

    return 0;
}
