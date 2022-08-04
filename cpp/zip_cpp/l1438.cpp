#include "../tool/helper.cpp"
using namespace std;

/*
description:
思路：
    通过维护一个集合/列表，能找到最大最小值之差
    每次进去一个最新的数字，如果[最大最小值之差]不符合要求，则尝试补偿此次的进入，将列表中第一次进入的数据剔除
    所有数字遍历完成后，列表长度为所求
*/

// Class Solution
class Solution {
  public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int i = 0, j = 0;
        while (j < nums.size()) {
            mp[nums[j]] = j;
            // cout << "j:" << j <<" i:"<<i<< " begin:" << mp.begin()->first << " end:" << mp.rbegin()->first << endl;
            if (mp.rbegin()->first - mp.begin()->first > limit) {
                auto target = mp.find(nums[i]);
                if (target != mp.end() && target->second == i) {
                    mp.erase(target);
                }
                i++;
            }
            j++;
        }
        return j - i;
    }
};

int main() {
    Solution A;

    vector<int> vec{1, 1, 1, 2, 31, 91, 1, 2};
    int limit = 40;
    cout << A.longestSubarray(vec, limit);

    return 0;
}
