#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution {
  public:
    int superEggDrop(int K, int N) {
        if (K == 1 || N <= 2)
            return N;
        int p = 1;
        while (pow(2, p) < N + 1)
            p++;
        if (p <= K)
            return p;
        else {
            cout << "K=" << K << " N=" << N << endl;
            int result1 = superEggDrop(K - 1, N - pow(2, p - 1));  //少蛋
            int result2 = superEggDrop(K, pow(2, p - 1) - 1);      //不少蛋
            cout << "result1:" << result1 << " result2:" << result2 << endl;
            return max(result1, result2) + 1;
        }
    }
};

int main() {
    Solution A;
    int k, N;
    cin >> k;
    cin >> N;
    cout << "F=" << A.superEggDrop(k, N) << endl;

    return 0;
}
