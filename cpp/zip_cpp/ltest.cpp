#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution






int main()
{
    uint64_t trade_property = 268435456; 
    uint64_t payment_property = 2105345;
    bool is_upquickpass_tencent_trade = false;
    bool is_upquickpass_wechat_trade = false;
    if ( ((trade_property & 1UL<<28) != 0) &&
         ((payment_property & 1UL<<21) != 0) )
    {
        cout<<"111"<<endl;
        is_upquickpass_tencent_trade = true;
    }
    if ( (trade_property & (1UL<<28) == 0) &&
         (payment_property & (1UL<<21) != 0) )
    {
        cout<<"222"<<endl;
        is_upquickpass_wechat_trade = true;
    }

    return 0;
}
