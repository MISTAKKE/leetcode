#include "../tool/helper.cpp"
using namespace std;

/*
description:


 m个坑  / M个萝卜
 1. init: (0->m-1) 一开始将0->m-1 共m个数字放好

 2. 第m+1个数字进来时
    1/m+1 在 0
    1/m+1 在 1
    1/m+1 在 m-1
    1/m+1 不进来

 3. 第m+k个数字进来时  k = (1 ... M-m)
    1/m+k 在 0
    1/m+k 在 1
    1/m+k 在 m-1
    k/m+k 在 不进来

 3. 0 在原位的概率 应该等于m/M 思考如何构造这里的概率即可
    p = 1 * m/m+1 * m+1/m+2 *   ...   * M-1/M

*/

// Class Solution
class Solution {
  public:
    vector<int> nums2;
    Solution(vector<int>& nums) {
        nums2.swap(nums);
    }

    int pick(int target) {
        int ret = 0;
        int cnt = 0;  // target is hit cnt
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums2[i] == target) {
                cnt++;
                if ((rand() % cnt) == 0) {
                    ret = i;
                }
            }
        }
        cout << "cnt:" << cnt << endl;

        return ret;
    }
};

int main() {
    vector<int> vec{1, 2, 3, 3, 3, 3};
    Solution A(vec);
    vector<int> result(10, 0);
    for (int i = 0; i < 10; ++i) {
        result[A.pick(3)]++;
    }
    show(result);

    return 0;
}
