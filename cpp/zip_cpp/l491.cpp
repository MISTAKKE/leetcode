#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> tmp;
        dfs(ret, 0, tmp, nums);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
    void dfs(set<vector<int>>& ret, int now, vector<int>& tmp, vector<int>& nums) {
        for (int i = now; i < nums.size(); ++i) {
            if (tmp.size() != 0 && tmp.back() > nums[i])
                continue;
            tmp.push_back(nums[i]);
            if (tmp.size() > 1)
                ret.insert(tmp);
            dfs(ret, i + 1, tmp, nums);
            tmp.pop_back();
        }
    }
};

int main() {
    Solution A;
    vector<int> nums{4, 6, 7, 7};
    show(A.findSubsequences(nums));

    return 0;
}
