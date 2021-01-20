#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>{};
        vector<string> mp{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret{""};
        for(int i = 0; i<digits.size(); ++i)
        {
            vector<string> result;
            string now = mp[digits[i]-'1'];
            for(int j = 0; j<now.size(); ++j)//jkl
            {
                for(int v = 0; v<ret.size(); ++v) 
                {
                    result.push_back(ret[v]+now[j]);
                }
            }
            ret = result;
        }

        return ret;
    }
};

int main()
{
    Solution A;
    show(A.letterCombinations("234"));

    return 0;
}
