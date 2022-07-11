#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution













int main()
{
    uint32_t uint32max_val = 0xffffffff;
    cout<<"uint32max_val: "<< uint32max_val << endl;        //4294967295
    uint64_t uint64_val1 = uint32max_val + 10;
    uint64_t uint64_val2{uint32max_val + 10 + 10L};
    uint64_t uint64_val3 = uint32max_val + 10L + 10L;
    uint64_t uint64_val4 = 10L + uint32max_val;
    uint64_t uint64_val5 = (uint64_t)uint32max_val + 10;
    uint32_t uint64_val6{uint64_val5};
    cout<<"uint64_val1: "<< uint64_val1 << endl;            //9
    cout<<"uint64_val2: "<< uint64_val2 << endl;            //19
    cout<<"uint64_val3: "<< uint64_val3 << endl;            //4294967315
    cout<<"uint64_val4: "<< uint64_val4 << endl;            //4294967305
    cout<<"uint64_val5: "<< uint64_val5 << endl;            //4294967305
    cout<<"uint64_val6: "<< uint64_val6 << endl;
    return 0;
}
