#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    bool isHappy(int n) {
        set<int> notokset;
        while (notokset.find(n) == notokset.end()) {
            notokset.insert(n);
            int val = get(n);
            if (val == 1) {
                show(notokset);
                return true;
            }
            n = val;
        }
        show(notokset);
        return false;
    }
    int get(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

int main() {
    Solution A;
    cout << A.isHappy(82) << endl;

    return 0;
}
