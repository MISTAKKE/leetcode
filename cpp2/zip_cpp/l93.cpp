#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return check(s, 0, 4);
    }
    bool isok(string &str)
    {
        bool flag = false;
        if(str[0]=='0' && str.size()!=1)
            flag = false;
        else if(str.size()!=3)
            flag = true;
        else if(str<="255")
            flag = true;
        print (str, flag);
        return flag;
    }
    vector<string> check(string &str, int s, int cnt)
    {
        //from str[s:e-1] make total cnt [0, 255]
        vector<string>ret;
        if(cnt==1)
        {
            string tmp = str.substr(s, str.size()-s);
            if(isok(tmp))
                ret.push_back(tmp);
            return ret;
        }
        if (str.size()-s == cnt)
        {
            print("sfsdfsf");
            string thisone = str.substr(s, 1);
            if(!isok(thisone))
                return ret;
            for(int i=1; i<cnt; ++i)
            {
                string ttmp = str.substr(s+i, 1);
                if(!isok(ttmp))
                    return ret;
                thisone = thisone + "." + ttmp; 
            }
            ret.push_back(thisone);
            return ret;
        }
        else if(str.size()-s != cnt*3)
        {
            //第一个的长度为i
            for(int i = 1; i<=3; ++i)
            {
                if(str.size()-s-i<cnt-1)//第一个太长了
                    break;
                else if (str.size()-s-i> 3 * (cnt-1))//第一个太短了
                    continue;
                string thisone = str.substr(s, i);
                if(!isok(thisone))//第一个太大了
                    break;
                vector<string> rettmp = check(str, s+i, cnt-1);
                for(int j = 0; j<rettmp.size(); ++j)
                {
                    ret.push_back(thisone + "." + rettmp[j]);
                }
            }
            return ret;
        }
        else//e-s == 3*cnt
        {
            string res = str.substr(s, 3);
            if(!isok(res))
                return ret;
            for(int i =1; i<cnt; ++i)
            {
                string tmp = str.substr(s+3*i, 3);
                if(!isok(tmp))
                    return ret;
                res = res + "."+ tmp;
            }
            ret.push_back(res);
            return vector<string>{ret};
        }
    }
};

int main()
{
    Solution A;
    show(A.restoreIpAddresses("010010"));
    string str = "101";
    //show(A.check(str, 0, 2));

    return 0;
}
