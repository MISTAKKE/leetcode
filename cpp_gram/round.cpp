#include "round_utils.h"
#include <cmath>
#include <limits>

double CRoundUtils::Round(double dValue) {
    return Round(dValue, 0);
}

double CRoundUtils::Round(double dValue, int iDigit) {
    return Round(dValue, iDigit, ROUND_TO_EVEN);
}

double CRoundUtils::Round(double dValue, int iDigits, EMidpointRounding eMode) {
    if (dValue < 0) {
        return -Round(-dValue, iDigits, eMode);
    }

    double dFractionMultiplier = std::pow(10.0, iDigits);
    dValue *= dFractionMultiplier;

    // 银行家舍入算法
    if (eMode == ROUND_TO_EVEN) {
        double dIntPart = 0;
        double dFracPart = modf(dValue, &dIntPart);

        if (fabs(dFracPart - 0.5) <= std::numeric_limits<double>::epsilon()) {
            if (std::fmod(dIntPart, 2.0) <= std::numeric_limits<double>::epsilon()) {
                return dIntPart / dFractionMultiplier;
            }

            return std::ceil(dIntPart + 0.5) / dFractionMultiplier;
        }
    }

    return std::floor(dValue + 0.5) / dFractionMultiplier;
}
