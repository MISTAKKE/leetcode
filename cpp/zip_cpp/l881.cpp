#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution1 {
  public:
    /*
思路：
    1 排序，船上从最大开始载人，如果最小的人都无法匹配到最大的人，那么最大的人单独走
    2 起始最大者为i，末尾最小者为j，i同样可以表示走了多少艘船
*/
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), std::greater<int>());
        int i = 0, j = people.size() - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                j--;
            }
            i++;
        }

        return i;
    }
};
class Solution {
  public:
    /*
    思路：
        1. 1<= people[i] <= limit <= 30000 [重量最大为3000 考虑计数排序]
        2. 第二步try to take minval away 时，可能两者相等，从而减除负值；第三四步需要判断小于0的情况
*/
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int maxval = people[0];  //  1 <= people.length <= 50000
        int minval = people[0];
        vector<short> num(30001, 0);  //(weigth, cnt)
        for (auto& i : people) {
            num[i] += 1;
            maxval = max(maxval, i);
            minval = min(minval, i);
        }
        // cout << "minval:" << minval << " maxval:" << maxval << endl;

        while (maxval >= minval) {
            // make one maxval cross the river
            --num[maxval];
            ++count;

            // try to take minval away
            if (minval + maxval <= limit) {
                --num[minval];
            }

            // update maxval minval
            while (num[maxval] <= 0 && maxval >= minval) {
                --maxval;
            }
            while (num[minval] <= 0 && maxval >= minval) {
                ++minval;
            }
        }
        return count;
    }
};

int main() {
    Solution A;
    vector<int> people = {1, 1, 2, 2};
    int limit = 5;
    cout << A.numRescueBoats(people, limit) << endl;

    return 0;
}
