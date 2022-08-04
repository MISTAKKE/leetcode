#include "../tool/helper.cpp"
using namespace std;

/*
description:
n == boxes.length
1 <= n <= 2000
boxes[i] 为 '0' 或 '1'

-------dis1|dis2-------
init:
idx = 0;
dis1 = 0;
dis2 += i*boxes[i];

mid:
dis1 += i*boxes[i];
dis2 -= i*boxes[i];

ret[i] = dis1 + dis2;
*/

// Class Solution
class Solution {
  public:
    vector<int> minOperations(string boxes) {
        vector<int> ret(boxes.size(), 0);
        int dis1 = 0, dis2 = 0;
        int left = 0, right = 0;
        for (int i = 0; i < boxes.size(); ++i) {
            dis2 += (boxes[i] - '0') * (i + 1);
            right += (boxes[i] - '0');
        }
        for (int i = 0; i < boxes.size(); ++i) {
            // cout << "i:" << i << " left:" << left << " right:" << right << " ret[i]:" << ret[i] << " dis1:" << dis1
            // << " dis2:" << dis2 << endl;
            dis1 += left;
            dis2 -= right;
            ret[i] = dis1 + dis2;
            left += (boxes[i] - '0');
            right -= (boxes[i] - '0');
            // cout << "i:" << i << " left:" << left << " right:" << right << " ret[i]:" << ret[i] << " dis1:" << dis1
            // << " dis2:" << dis2 << endl;
        }
        return ret;
    }
};

int main() {
    Solution A;
    std::string str = "110";  // 1, 1, 3
    // std::string str = "001011";//11, 8, 5, 4, 3, 4
    show(A.minOperations(str));

    return 0;
}
