#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
在第n天的时候
现有：  10个湖是满的   7个湖的空的
未来：  不下雨的，  要下雨的  

*/

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        vector<int> out;       //输出的操作序列
        set<int> full;
        int idx = 0;
        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i] == 0) //当天晴天，准备排水
            {
                cout << "第" << i << "天，今天是晴天 idx:" << idx << endl;
                //找到下个雨天，且把它值为空
                while (idx < rains.size())
                {
                    if(full.count(rains[idx])==1)
                        break; //找到第一个满了的水库天数idx  其水库为rains[idx]
                    idx++;
                }
                if (idx != rains.size())
                {
                    full.erase(rains[idx]);
                    out.push_back(rains[idx]);
                    cout << "第" << i << "天，把" << rains[idx] << "的水排了 idx:" << idx << endl;
                    ++idx;
                }
                else
                {
                    out.push_back(1);
                    cout << "今天是晴天，但没活干，摸鱼" << endl;
                }
            }
            else //当天雨天，准备放工
            {
                cout << "第" << i << "天，今天是雨天 idx:" << idx << endl;
                if(full.count(rains[idx])==1)
                {
                    cout << "i:" << i << " 把" << rains[i] << "的水库满上了， 房塌了" << endl;
                    return vector<int>();
                }
                full.insert(rains[i]);
                cout << "第" << i << "天，把" << rains[i] << "的水库满上了" << endl;
                out.push_back(-1);
                idx = i + 1;
            }
        }
        return out;
    }
};

int main()
{
    Solution A;
    vector<int> vec{1,0,2,0};
    show(A.avoidFlood(vec));
    return 0;
}