#include "../tool/helper.cpp"
using namespace std;

/*
description:

0 1 2 3 4 5 6 7 |8| 9 10 11 12 13
0 - 7 [删除8]  9 - 13
    0-7 没有reverse 奇数和偶数分别是多少
    9-13 被reverse 奇数和偶数分别是多少
dp[0] = nums[0], 0
dp[1] = nums[1], nums[0]
...
O(n)

删除8 = f(8) = 所有的奇数 == 所有的偶数
所有的奇数 == [0-7][奇数] + [9-13]偶数
所有的偶数 == [0-7][偶数] + [9-13]奇数

[9-13]偶数 = 所有偶数 - [0-8]偶数
[9-13]奇数 = 所有奇数 - [0-8]奇数


*/

// Class Solution

class Solution {
  public:
    int waysToMakeFair1(vector<int>& nums) {
        vector<int> odd(nums.size(), 0);
        vector<int> even(nums.size(), 0);
        int oddval = 0;
        int evenval = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            oddval += nums[i] * (i % 2);
            evenval += nums[i] * ((i + 1) % 2);
            odd[i] = oddval;
            even[i] = evenval;
        }
        show(nums);
        show(odd);
        show(even);

        for (int i = 1; i < nums.size(); ++i) {
            int theodd = odd[i - 1] + evenval - even[i];
            int theeven = even[i - 1] + oddval - odd[i];
            ret += (theodd == theeven);
        }

        ret += (evenval - nums[0] == oddval);
        cout << "ret:" << ret << endl;
        ;

        return ret;
    }

    int waysToMakeFair2(vector<int>& nums) {
        vector<int> diff(nums.size(), 0);
        int oddval = 0;
        int evenval = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            oddval += nums[i] * (i % 2);
            evenval += nums[i] * ((i + 1) % 2);
            diff[i] = evenval - oddval;
        }
        show(diff);
        for (int i = 1; i < nums.size(); ++i) {
            cout << "i:" << endl;
            cout << "diff[i-1]:" << diff[i - 1] << endl;
            cout << "diff[i]:" << diff[i] << endl;
            cout << "diff[nums.size()-1]" << diff[nums.size() - 1] << endl << endl;
            int k = (diff[i - 1] + diff[i] - diff[nums.size() - 1]);
            ret += (k == 0 ? 1 : 0);
        }
        ret += (diff[nums.size() - 1] == nums[0]);
        cout << "ret:" << ret << endl;
        return ret;
    }

    int waysToMakeFair3(vector<int>& nums) {
        int ret = 0;
        int evendiffold = 0;
        for (int i = 0; i < nums.size(); ++i) {
            evendiffold += nums[i] * ((i + 1) % 2) - nums[i] * (i % 2);
        }
        int oddval1 = 0;
        int evenval1 = nums[0];
        int diffi_1 = nums[0];
        int diffi = 0;
        for (int i = 1; i < nums.size(); ++i) {
            oddval1 += nums[i] * (i % 2);
            evenval1 += nums[i] * ((i + 1) % 2);
            diffi = evenval1 - oddval1;
            // cout<<"oddval1:"<<oddval1<<endl;
            // cout<<"evenval1:"<<evenval1<<endl;
            // cout<<"diffi_1:"<<diffi_1<<" diffi:"<<diffi<<endl<<endl;
            int k = (diffi + diffi_1 - evendiffold);
            ret += (k == 0 ? 1 : 0);
            diffi_1 = diffi;
        }

        ret += evendiffold == nums[0];
        return ret;
    }

    int waysToMakeFair(vector<int>& nums) {
        int evendiffold = 0;
        for (int i = 0; i < nums.size(); ++i) {
            evendiffold += nums[i] * ((i + 1) % 2) - nums[i] * (i % 2);
        }
        int oddval1 = 0;
        int evenval1 = nums[0];
        int diffi_1 = nums[0];
        int diffi = 0;
        int ret = 0;
        for (int i = 1; i < nums.size(); ++i) {
            oddval1 += nums[i] * (i % 2);
            evenval1 += nums[i] * ((i + 1) % 2);
            diffi = evenval1 - oddval1;
            ret += (diffi + diffi_1 - evendiffold == 0 ? 1 : 0);
            diffi_1 = diffi;
        }

        ret += evendiffold == nums[0];
        cout << "ret:" << ret << endl;
        return ret;
    }
};

int main() {
    Solution A;
    vector<int> nums{2, 1, 6, 4};
    // vector<int>nums{0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    A.waysToMakeFair(nums);

    return 0;
}
