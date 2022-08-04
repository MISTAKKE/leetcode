#include <stdint.h>

class CRoundUtils {
  public:
    enum EMidpointRounding { ROUND_TO_EVEN, ROUND_AWAY_FROM_ZERO };

    static double Round(double dValue);
    static double Round(double dValue, int iDigits);
    static double Round(double dValue, int iDigits, EMidpointRounding eMode);
};
