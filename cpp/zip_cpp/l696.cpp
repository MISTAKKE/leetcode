#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int a = 0;
        int b = 0;
        char c = '2';
        int ret = 0;
        for(int i = 0; i< s.size(); ++i)
        {
            if(c != s[i])
            {
                c = s[i];
                ret += min(a, b);
                if(s[i]=='0')
                    a = 1;
                else
                    b = 1;
            }
            else
            {
                if(s[i] == '0')
                    a++;
                else
                    b++;
            }
        }
        ret += min(a, b);

        return ret;
    }
};


int main()
{
    Solution A;
    string str = "10101";
    print(str, A.countBinarySubstrings(str));

    return 0;
}
