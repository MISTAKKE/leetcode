#include "../tool/helper.cpp"
#include <stdio.h>
#include <string.h>
using namespace std;

/*
description:


*/

// Class Solution
const uint32_t MOD_ADLER = 65521;

uint32_t adler32(char* data, size_t len)
/*
    where data is the location of the data in physical memory and
    len is the length of the data in bytes
*/
{
    uint32_t a = 1, b = 0;
    size_t index;

    // Process each byte of the data in order
    for (index = 0; index < len; ++index) {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}

int main() {
    // char *str = "Wikipedia";
    char* str = "1233297802";
    int result = adler32(str, 10);
    cout << "result:" << result << endl;

    return 0;
}
