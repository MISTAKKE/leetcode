#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    string find(map<string, string> &father, string key)
    {
        string son = father[key];
        while (key != father[key])
        {
            key = father[key];
        }
        while (son != key)
        {
            string tmp = father[son];
            father[son] = key;
            son = tmp;
        }
        return key;
    }
    void merge(map<string, string> &father, string key1, string key2)
    {
        //key1 = find(father, key1);//key1 不存在在map中
        key2 = find(father, key2);
        father[key1] = key2;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        map<string, string> father; //union father
        map<string, string> head;   //mark email to name
        vector<vector<string>> res; //return
        for (auto account : accounts)
        {
            for (int i = 1; i < account.size(); ++i)
            {
                if (father.find(account[i]) == father.end())
                {
                    if (i == 1)
                    {
                        father[account[1]] = account[1];
                        head[account[1]] = account[0];
                    }
                    merge(father, account[i], account[1]);
                }
                else
                {
                    merge(father, account[i], father.find(account[i])->second);
                }
            }
        }
        show(father);
        map<string, set<string>> mp; //root {son list}
        for (auto iter = father.begin(); iter != father.end(); ++iter)
        {
            string root = find(father, iter->first);
            if (mp.find(root) == mp.end())
            {
                mp[root] = {iter->first};
            }
            else
            {
                mp[root].insert(iter->first);
            }
        }
        for (auto key = mp.begin(); key != mp.end(); ++key)
        {
            vector<string> re = {head[key->first]};
            for (auto iter = key->second.begin(); iter != key->second.end(); ++iter)
                re.push_back(*iter);
            res.push_back(re);
        }
        return res;
    }
};

int main()
{
    Solution A;
    //vector<vector<string>> acc {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    //show(acc);
    //show(A.accountsMerge(acc));
    //   John johnsmith@mail.com john00@mail.com
    //   John johnnybravo@mail.com
    //   John johnsmith@mail.com john_newyork@mail.com
    //   Mary mary@mail.com

    //   John johnnybravo@mail.com
    //   John john00@mail.com john_newyork@mail.com johnsmith@mail.com
    //   Mary mary@mail.com

    //vector<vector<string>> acc{{"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"}, {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"}, {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"}, {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"}, {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"}};
    vector<vector<string>> acc{{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"}, {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"}};
    //vector<vector<string>> acc{{"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"}};
    show(acc);
    show(A.accountsMerge(acc));
    return 0;
}
