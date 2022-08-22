#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{vector<int>{}};
        helper(ans, nums, 0);
        return ans;
    }
    void helper(vector<vector<int>> &ans, vector<int>& nums, int idx){
        if(idx == nums.size()){
            return;
        }
        int cnt = ans.size();
        for(int i = 0; i<cnt; ++i){
            vector<int> cur = ans[i];
            cur.push_back(nums[idx]);
            ans.push_back(cur);
        }
        helper(ans, nums, idx+1);
    }
};



// Class Solution
class Solution2 {
  public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>());
        help(nums, 0);
        return res;
    }
    void help(vector<int>& nums, int idx) {
        if (nums.size() == idx) {
            return;
        }
        int cnt = res.size();
        for (int i = 0; i < cnt; ++i) {
            vector<int> nvec = res[i];
            nvec.push_back(nums[idx]);
            res.push_back(nvec);
        }
        help(nums, idx + 1);
    }
};

int main() {
    Solution A;
    vector<int> nums{1, 2, 3};
    show(A.subsets(nums));
    cout << A.subsets(nums).size() << endl;
    return 0;
}
