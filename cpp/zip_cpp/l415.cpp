#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    string addStrings1(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string s(max(m, n), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(n>m)
            num1 += string(n-m, '0');
        else
            num2 += string(m-n, '0');
        int add = 0;
        for(int i = 0; i<n || i<m; ++i)
        {
            int res = add + num1[i] + num2[i] - '0' - '0';
            add = res / 10;
            s[i] = res % 10 + '0';
        }
        if(add != 0)
            s += add + '0';
        reverse(s.begin(), s.end());
        return s;
    }
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        int add = 0;
        int left, right;
        string s(max(m, n), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i<n || i<m; ++i)
        {
            if(i<m)
                left = num1[i] - '0';
            else
                left = 0;
            if(i<n)
                right = num2[i] - '0';
            else
                right = 0;
            add = add + left + right;
            s[i] = add % 10 + '0';
            add = add / 10;
        }
        if(add != 0)
            s += add + '0';
        reverse(s.begin(), s.end());
        return s;
    }
};


int main()
{
    Solution A;
    string s1 = "9";
    string s2 = "1";
    print(A.addStrings(s1, s2));

    return 0;
}
