#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 1;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                count++;
            }
            else {
                // 0 1 2 -> 0
                // 3 4   -> 1
                // 5 6   -> 2
                n -= (count - 1) / 2;
                count = 0;
            }
        }
        count += 1;
        n -= (count - 1) / 2;
        return n <= 0 ? true : false;
    }
};

int main() {
    Solution A;
    vector<int> flowerbed{0, 0, 0, 0, 1, 1, 1, 0, 0, 0};
    cout << A.canPlaceFlowers(flowerbed, 4) << endl;
    return 0;
}
