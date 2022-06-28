#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
/*
本质: l300的扩展  最长递增子序列（Longes Increasing Subsequence，简写为 LIS）

解法:
1. 排序: 第一列递增 第一列相同时第二列递减
2. 对于第二列使用 lis即可

解释:
1. 未排序时，两个信封相比有9种可能性，(大 等 小) * (大 等 小)，在使用第一列增序排序后，去掉了三种可能性
2. 第二列应使用什么方式排序呢?现逐个分析当前信封与有效信封的最后一个 相比的6种情况:
    大 大 -> 放进有效队列
    大 等 -> 废弃
    大 小 -> 可能有用(因为第一列已经增序，后面的一定比这个大)
    等 大 -> 废弃
    等 等 -> 废弃
    等 小 -> 可能有用(因为第一列已经增序，后面的一定比这个大)

结论:
仅处理三种情况:
    1. 大 大 -> 放进有效队列
    2. 大 小 -> 可能有用(因为第一列已经增序，后面的一定比这个大)
    3. 等 小 -> 可能有用(因为第一列已经增序，后面的一定比这个大)
如果将第二列设计成递增的
    env = [ (1,1), (2,4), (12,3), (12,5) ]
    在处理(12,3) 时，不能将其放进去，否则一定会导致(12,5)进不去，从而不是最优方案
    结论: 第二列不能设计为递增的
将第二列设计成递减的，第 2 3 种情况都可能出现，将有效信封的第二列(递增)二分查找即可

更优的解法:
将有效队列仅保留第二列的值，无视第一列的值
*/
class Solution_better {
  public:
    //所有pair排序 第一列增序 第二列降序
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 1) {
            return 1;
        }
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> res{envelopes[1]};
        for (auto c : envelopes) {
            if (c[0] >)
        }
    }
};

class Solution {
  public:
    //所有pair排序 第一列增序 第二列降序
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
    }
    //有效信封排序 仅看第二列-增序
    static bool comp2(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 1) {
            return 1;
        }
        sort(envelopes.begin(), envelopes.end(), comp);
        //有效信封排序
        vector<vector<int>> res{envelopes[0]};
        for (auto c : envelopes) {
            if (c[0] > res.back()[0] && c[1] > res.back()[1]) {
                res.push_back(c);
            }
            else if (c[1] < res.back()[1]) {
                int idx = lower_bound(res.begin(), res.end(), c, comp2) - res.begin();
                res[idx] = c;
            }
        }
        return res.size();
    }
};
int main() {
    Solution A;
    vector<vector<int>> envelopes{{1, 8}, {2, 5}, {6, 4}, {6, 7}, {5, 2}, {5, 4}, {2, 10}, {1, 1}};
    cout << A.maxEnvelopes(envelopes) << endl;

    return 0;
}
