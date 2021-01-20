#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        int emptyidx = -1;
        vector<int> reverselist;
        vector<int> samelist;
        for(int i = 0; i<n; ++i)
        {
            string &str = words[i];
            if(str.empty())
            {
                emptyidx = i;
                continue;
            }
            else if(isreverse(str, 0, str.size()-1))
            {
                reverselist.push_back(i);
            }
            for(int j=0; j<str.size()-1; ++j)
            {
                if(isreverse(str, 0, j))
                {
                    int idx = findx(str, j+1, str.size()-1, words);
                    if(idx!=-1)
                    {
                        res.push_back({idx, i});
                    }
                }
                if(isreverse(str, str.size()- 1 -j, str.size()-1))
                {
                    int idx = findx(str, 0, str.size()- 2 -j, words);
                    if(idx!= -1)
                    {
                        res.push_back({i, idx});
                    }
                }
            }
            int idx = findx(str, 0, str.size()-1, words);
            if(idx!=-1)
            {
                if(i ==idx)
                    continue;
                res.push_back({i, idx});
            }
        }
        if(emptyidx !=-1)
        {
            for(int i = i = 0; i<reverselist.size(); ++i)
            {
                res.push_back({emptyidx, reverselist[i]});
                res.push_back({reverselist[i], emptyidx});
            }
        }
        
        return res;
    }

    int findx(string& str, int s, int e, vector<string>& words)
    {
        for(int i = 0; i< words.size(); ++i)
        {
            if(words[i].size() != (e-s+1))
                continue;
            for(int j = 0; j< words[i].size(); ++j)
            {
                if(words[i][j] != str[e-j])
                    continue
            }
            return i;
        }
        return -1;
    }

    bool isreverse(string &str, int s, int e)
    {
        int i = 0;
        while(i<=((e-s)/2))
        {
            if(str[s+i] == str[e-i])
                i++;
            else
                return false;
        }
        return true; 
    }
};

int main()
{
    Solution A;
    vector<string> res={"abcd","dcba","lls","s","sssll"};
    show(A.palindromePairs(res));

    return 0;
}
