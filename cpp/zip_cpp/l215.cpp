#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() != k) {
                q.push(nums[i]);
            }
            else if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};
class Solution2 {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;  //小顶堆
        for (auto& i : nums) {
            if (q.size() == k) {
                if (i > q.top()) {
                    q.pop();
                    q.push(i);
                }
            }
            else {
                q.push(i);
            }
        }
        return q.top();
    }
};

int main() {
    Solution A;
    vector<int> vec{3, 2, 1, 5, 6, 4};
    cout << A.findKthLargest(vec, 3) << endl;

    return 0;
}
