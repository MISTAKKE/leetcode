#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
给你两个整数数组 arr1 和 arr2，返回使 arr1 严格递增所需要的最小「操作」数（可能为 0）。
每一步「操作」中，你可以分别从 arr1 和 arr2 中各选出一个索引，分别为 i 和 j，0 <= i < arr1.length 和 0 <= j <
arr2.length，然后进行赋值运算 arr1[i] = arr2[j]。 如果无法让 arr1 严格递增，请返回 -1。

 

示例 1：
输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
输出：1
解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。

示例 2：
输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]
输出：2
解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。

示例 3：
输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
输出：-1
解释：无法使 arr1 严格递增。
 
提示：
1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/

// Class Solution

class Solution {
  public:
    int maxval = 1e9;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        //将arr2排序、去重
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        // show(arr2);
        arr1.insert(arr1.begin(), -1);
        arr1.push_back(maxval + 1);
        std::vector<int> dp(arr1.size(), maxval);  //满足当前性质时 最小的步数
        dp[0] = 0;
        for (int i = 1; i < arr1.size(); ++i) {
            //最大能选择的值的idx
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            //最多替换k个节点
            for (int k = 1; k <= min(i - 1, j); ++k) {
                // i不动 换i前面的k个点 是否满足要求
                if (arr1[i - k - 1] < arr2[j - k])
                    dp[i] = min(dp[i], dp[i - 1 - k] + k);
            }
            //不替换
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i - 1], dp[i]);
            }
        }

        return dp[arr1.size() - 1] == maxval ? -1 : dp[arr1.size() - 1];
    }
};

class Solution1 {
  public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        //将arr2去重排序后记为 vec2
        std::set<int> s2(arr2.begin(), arr2.end());
        std::vector<int> vec2(s2.begin(), s2.end());
        std::sort(vec2.begin(), vec2.end());
        show(vec2);
        //当前始终维持性质时 key=最小次数 value=最小的值
        std::map<int, int> mp;
        //第0个数 次数=0 最小值为自己
        mp[0] = arr1[0];
        if (vec2[0] < arr1[0]) {
            //第0个数 次数=1 最小值为vec2[0]
            mp[1] = vec2[0];
        }
        //轮询第1 到 第n个数
        for (int i = 1; i < arr1.size(); ++i) {
            if (mp.size() == 0)
                return -1;
            std::map<int, int> mp2;
            for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
                int times = iter->first;
                //不进行任何交换
                if (arr1[i] > mp[times]) {
                    if (mp2.find(times) == mp2.end())
                        mp2[times] = arr1[i];
                    else
                        mp2[times] = min(mp2[times], arr1[i]);
                }
                // vec2中不存在了
                if (mp[times] >= vec2[vec2.size() - 1]) {
                    continue;
                }
                //将upper作为最小的数
                int upper = std::upper_bound(vec2.begin(), vec2.end(), mp[times]) - vec2.begin();
                cout << "i:" << i << " upper:" << upper << endl;
                if (mp2.find(times + 1) == mp2.end())
                    mp2[times + 1] = vec2[upper];
                else
                    mp2[times + 1] = min(mp2[times + 1], vec2[upper]);
            }
            cout << "i:" << i << endl;
            show(mp);
            show(mp2);
            mp = mp2;
        }
        if (mp.empty())
            return -1;
        int retval = arr1.size();
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            retval = min(retval, iter->first);
        }
        return retval;
    }
};
int main() {
    Solution A;
    vector<int> v1{1, 5, 3, 6, 7};
    vector<int> v2{1, 3, 4};
    cout << A.makeArrayIncreasing(v1, v2) << endl;
    return 0;
}
