#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    double e = 0.001;
    bool judgePoint24(vector<int>& nums) {
        //4 -> 3
        //  4 * 3 * (4) = 16*3 = 48
        //3 -> 2
        //  3 * 2 * (4) = 24
        //2 -> 1
        //  2 * 1 * 4 = 8
        //  48 * 24 * 8 = 9216
        for(int i = 0; i< 4; ++i)
        {
            for(int j =0; j<4; ++j)
            {
                vector<int> choose{0,0,0,0};
                if(i ==j)
                    continue;
                choose[i] = 1;
                choose[j] = 1;
                int m=-1, n=-1;
                //int m n 是 0 1 2 3中非i j的两个
                for(int k = 0;k<4;++k)
                {
                    if(m==-1 && choose[k]==0)
                    {
                        m = k;
                        continue;
                    }
                    if(choose[k]==0)
                    {
                        n = k;
                    }
                }
                for(int q = 0; q<4; ++q)
                {
                    double d = val(q, nums[i], nums[j]);
                    vector<double> res{d, nums[m], nums[n]};
                    if(i == 1 && j == 2 && q==3)
                        print("1346:", d, nums[m], nums[n]);
                    if(check3(res)) return true;
                }

            }
        }
        return false;
    }

    bool check3(vector<double> vec)
    {
        double d;
        for(int i = 0; i< 3; ++i)
        {
            for(int j = 0; j<3; ++j)
            {
                if(i==j)
                    continue;
                int k = 3 - i - j;
                for(int m = 0; m<4; ++m)
                {
                    double d = val(m, vec[i], vec[j]); //0.75 1 6
                    if(vec[0] ==0.75 &&  i == 1 && j == 0 && m == 1)
                    {
                        print("1346:", d, vec[k]); 
                    }
                    if(d!=1000000)
                    {
                        if(check2(d, vec[k])) return true;
                        if(check2(vec[k], d)) return true;
                    }
                }
            }
        }
        return false;
    }

    bool check2(double a, double b)
    {
        for(int m = 0; m<4; ++m)
        {
            double d = val(m, a, b);
            if(issameval(d, 24))
            {
                //print("24:", a, m, b); 
                return true;
            }
        }
        return false;
    }

    double val(int op, double a, double b)
    {
        if(op == 0)   return a+b;
        if(op == 1)   return a-b;
        if(op == 2)   return a*b;
        if(op == 3)
            if(issameval(b, 0))
                return 1000000;
            else
                return a/b;
    }

    bool issameval(double a, double val)
    {
        if( a >= val - e && a<= val + e )
            return true;
        return false;
    }

};

int main()
{
    Solution A;
    vector<int> res{1,3,4,6};
    print(A.judgePoint24(res));

    return 0;
}
