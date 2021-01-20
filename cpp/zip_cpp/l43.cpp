#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    string multiply(string snum1, string snum2) {
        int n = snum1.size();
        int m = snum2.size();
        string res(n+m+1, '0');
        string num1 = '0' + snum1;
        string num2 = '0' + snum2;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int add = 0;
        for(int i = 0; i<=n; ++i)
        {
            for(int j = 0; j<=m; ++j)
            {
                add = res[i+j] - '0' + (num1[i] - '0')*(num2[j] - '0') + add;
                res[i+j] = (add % 10) + '0';
                add = add / 10;
            }
        }
        string ret;
        int end = res.size()-1;
        while(res[end]=='0')
            end-=1;
        for(int i = 0; i<=end; ++i)
            ret.insert(0, to_string(res[i]-'0'));
        if(ret=="")
            return "0";
        return ret;
    }
};


int main()
{
    Solution A;
    string s1 = "11111";
    string s2 = "9999999";
    print(A.multiply(s1, s2));

    return 0;
}
