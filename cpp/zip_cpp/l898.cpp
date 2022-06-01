#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
https://leetcode.cn/problems/bitwise-ors-of-subarrays/

description:
我们有一个非负整数数组 arr 。
对于每个（连续的）子数组 sub = [arr[i], arr[i + 1], ..., arr[j]] （ i <=
j），我们对 sub 中的每个元素进行按位或操作，获得结果 arr[i] | arr[i + 1] | ... |
arr[j] 。 返回可能结果的数量。 多次出现的结果在最终答案中仅计算一次。

 

示例 1：
输入：arr = [0]
输出：1
解释：
只有一个可能的结果 0 。

示例 2：
输入：arr = [1,1,2]
输出：3
解释：
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。

示例 3：
输入：arr = [1,2,4]
输出：6
解释：
可能的结果是 1，2，3，4，6，以及 7 。
 
1. arr数组每加一个长度 arr[k]，需要对比的次数为 arr[0..k]  arr[1..k] ...
arr[k]一共k个数
2. 但是上面k各个数除了最后一个以外，都之和前一次循环的
arr[k-1]有关系，所以维护上一次的运行结果记录即可
3. 数字从后向前是主键累加的，并且最大是10^9=32b，所以每一轮最多只有32个数字
4. 时间复杂度=O(N * m)；空间复杂度=O(N + m) 其中m=32
*/

// Class Solution
class Solution {
  public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        std::set<int> ans;
        std::set<int> cur{0};
        for (auto& c : arr) {  // O(N)
            std::set<int> cur2{c};
            for (auto& c2 : cur)  // O(常数<=32)
            {
                cur2.insert(c2 | c);
            }
            cur = cur2;
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
};

int main()
{
    Solution    A;
    vector<int> arr{1, 2, 4};
    cout << A.subarrayBitwiseORs(arr) << endl;
    return 0;
}
