#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution



#include <iostream>
#include <vector>
using namespace std;
vector<int> findmax(const string &s)
{
    vector<int> vecright(26,0);//字符串s中每个字符的最右值
    vector<int> vecret;
    for(int i =0;i<s.size();++i)
    {
        vecright[s[i]-'a'] = i;
    }
    int start = -1;
    int maxval = 0;//当前段最右端的值
    for(int i =0;i<s.size();++i)
    {
        maxval = max(vecright[s[i]-'a'], maxval);
        if(i == maxval)
        {
            vecret.push_back(maxval-start);
            start = maxval;
        }
    }

    return vecret;
}

int main() {
    string s = "ababcbacazczdefegdehijhklij";
    //ababcbaca defegde hijhklij
    vector<int> vecret = findmax(s);
    for(auto c:vecret)
        cout<<c<<endl;
    cout << "Hello World!" << endl;
}

// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//  "ababcbacadefegdehijhklij"
//  "ababcbaca defegde hijhklij"
// [9,7,8]