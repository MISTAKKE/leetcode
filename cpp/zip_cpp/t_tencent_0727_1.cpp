#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(int count, int k)
{
    vector<int> vec;
    int tmp;
    int cnt = 1;
    vector<int> pass;
    for(int i = 0; i<count; ++i)
    {
        cin>>tmp;
        // cout<<"   in:"<<tmp<<endl;
        pass.push_back(tmp);
    }
    cin>>tmp;
    int tencent_score = pass[0] + tmp;
    // cout<<"count:"<<count<<endl;
    // cout<<"k:"<<k<<endl;
    for(auto c: pass)
        if(c > tencent_score)
        {
            cnt+=1;
        }
    // cout<<"cnt:"<<cnt<<endl;
    // cout<<"tencent_score:"<<tencent_score<<endl;
    for(int i = 1; i<count; ++i)
        cin>>tmp;
    return cnt <= k;
}

int main()
{
    int n ;
    cin>>n;
    vector<bool>res;
    while(n--)
    {
        int count;
        cin >> count;
        int k;
        cin >> k;
        res.push_back(f(count, k));
    }
    for(auto c:res)
    {
        if(c)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
