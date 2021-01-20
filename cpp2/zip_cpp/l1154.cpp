#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        //2019-02-10
        int year=0;
        for(int i = 0;i<4;++i)
            year = year * 10 + (date[i] -'0');
        int month = (date[5]-'0')*10 + date[6] - '0';
        int day = (date[8]-'0')*10 + date[9] - '0';
        bool runnian= year%100==0 ? (year%400==0 ? true:false) : (year%4==0 ? true : false);
        vector<int>days{0,31,28,31,30,31,30,31,31,30,31,30,31};
        int ret = 0;
        int m=month;
        while(--m)
        {
            ret += days[m];
        }
        ret += (day + (month >=3) * runnian);
        print(year, month, day, runnian);
        return ret;
    }
};


int main()
{
    Solution A;
    string str = "1969-09-28"; 
    print(str, "  ", A.dayOfYear(str));

    return 0;
}
