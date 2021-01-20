#include "../tool/helper.cpp"
using namespace std;



int main()
{
    long a = 671840;
    print(a);
    long b = 1<<17;
    a = a & ~b;
    print(a);


    return 0;
}
