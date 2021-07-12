#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
using namespace std;
#include <iostream>
#include "round.h"
using namespace std;

uint64_t CalculateCharge(const uint64_t ddwCareAmount,
        const double dChargeRate)
{
    double dResult = static_cast<double>(ddwCareAmount);
    dResult *= static_cast<double>(dChargeRate);
    dResult /= static_cast<double>(CHARGE_RATE_DENOMINATOR);
    return static_cast<uint64_t>(CRoundUtils::Round(dResult, 0, m_eRoundingMode));
}

int main(int argc, char** argv)
{
    uint64_t ddwNeedRefund = 1000000; //应退金额
    double rate = 999999 * 10000UL / 1000000; //本次申请退款金额/订单金额

    cout<<"rate:"<<rate<<endl;

    uint64_t ddwRefundFee = CalculateCharge(ddwNeedRefund, dRate); //本次退款金额

	return 0;
}
