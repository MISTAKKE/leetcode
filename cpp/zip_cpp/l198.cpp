#include "../tool/helper.cpp"
using namespace std;

/*
description:
    0 <= nums.length <= 100
    0 <= nums[i] <= 400
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int dorob = nums[0];
        int notrob = 0;
        for(int i = 1;i<nums.size();++i){
            int newdorob = max(nums[i] + notrob, dorob);
            notrob = max(notrob, dorob);
            dorob = newdorob;
        }
        return max(dorob, notrob);
    }
};
// Class Solution
class Solution1  // 4 param
{
  public:
    int rob(vector<int>& nums) {
        int do1 = 0, do2 = 0;
        int no1 = 0, no2 = 0;
        if (nums.size() == 0)
            return 0;
        do1 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            do2 = no1 + nums[i];
            no2 = max(do1, no1);
            do1 = do2;
            no1 = no2;
        }
        return max(do1, no1);
    }
};

class Solution3  // 3 param
{
  public:
    int rob(vector<int>& nums) {
        int do1 = 0, do2 = 0;
        int no = 0;
        if (nums.size() == 0)
            return 0;
        do1 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            do2 = no + nums[i];
            no = max(do1, no);
            do1 = do2;
        }
        return max(do1, no);
    }
};

int main() {
    Solution A;
    vector<int> res{2, 7, 9, 3, 1};
    cout << A.rob(res) << endl;

    return 0;
}
