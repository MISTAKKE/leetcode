#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1;
        int down = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                up = max(up, down + 1);
            }
            else if (nums[i - 1] > nums[i]) {
                down = max(up + 1, down);
            }
        }

        return max(up, down);
    }
};

int main() {
    Solution A;

    return 0;
}
