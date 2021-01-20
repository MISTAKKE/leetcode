#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        for(int i = 0; i<t.size(); ++i)
        {
            if(s[cnt] == t[i])
                cnt++;
            if(cnt==s.size())
                return true;
        }
        return false;
    }
};

int main()
{
    Solution A;
    string s = "asd";
    string t = "sfdsaweresrwe";
    print(A.isSubsequence(s, t));

    return 0;
}
