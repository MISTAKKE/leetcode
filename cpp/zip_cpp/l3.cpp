#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> vec(256, -1);
        int maxval = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int idx = vec[s[i]];
            if (idx != -1) //exist in vec
            {
                int val = 0;
                for (int k = 0; k < 256; ++k)
                {
                    if (vec[k] != -1)
                    {
                        val += 1;
                        if (vec[k] <= idx)
                        {
                            vec[k] = -1;
                        }
                    }
                }
                maxval = max(maxval, val);
            }
            vec[s[i]] = i;
        }
        int val = 0;
        for (int i = 0; i < 256; ++i)
        {
            if (vec[i] != -1)
            {
                val += 1;
            }
        }
        return max(maxval, val);
    }
};

int main()
{
    Solution A;
    string s = " ";
    cout << A.lengthOfLongestSubstring(s) << endl;

    return 0;
}
