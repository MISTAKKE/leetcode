#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd2(int m, int n) {
        //ret的最低位right, 小于等于right的都为0
        int i = 1;
        for(i = 1;i<32 && m>0;++i)
        {
            if(m==n && m%2 == 1 && m%2 ==1)
                break;
            m>>=1;
            n>>=1;
        }
        m = m << i -1;
        return m;
    }
    int rangeBitwiseAnd(int m, int n)
    {
        int shift = 0;
        while(m<n)
        {
            shift++;
            m>>=1;
            n>>=1;
        }
        return m <<shift;
    }
};

int main()
{
    Solution A;
    int a = 16;
    int b = 32;
    print(A.rangeBitwiseAnd(a,b));

    return 0;
}
