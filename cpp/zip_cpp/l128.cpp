#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int longestConsecutive1(vector<int>& nums) {
        std::map<int, int> father;
        int valmax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            father[nums[i]] = nums[i];
            if (father.find(nums[i] - 1) != father.end())
                father[nums[i]] = father[nums[i] - 1];
            if (father.find(nums[i] + 1) != father.end())
                father[nums[i] + 1] = father[nums[i]];
        }
        for (auto i = father.begin(); i != father.end(); ++i) {
            if (i->first == i->second)  // start
            {
                int key = i->first;
                int cnt = 1;
                while (father.find(key + cnt) != father.end() && father[key] <= father[key + cnt] &&
                       father[key + cnt] < father[key] + cnt) {
                    cnt += 1;
                }
                valmax = max(valmax, cnt);
            }
        }
        return valmax;
    }

    int longestConsecutive(vector<int>& nums) {
        set<int> se(nums.begin(), nums.end());
        int val = 1;
        for (const int& i : se) {
            if (!se.count(i - 1)) {
                int cnt = 1;
                while (se.count(i + cnt)) {
                    cnt += 1;
                }
                val = max(val, cnt);
            }
        }
        return val;
    }
};

int main() {
    Solution A;
    vector<int> vec{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // vector<int> vec{100,4,200,1,3,2};
    cout << A.longestConsecutive(vec) << endl;
    return 0;
}
