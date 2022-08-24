#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!q.empty() && temperatures[q.top()] < temperatures[i]) {
                res[q.top()] = i - q.top();
                q.pop();
            }
            q.push(i);
        }
        return res;
    }
};
class Solution1 {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> sk;  //内容为idx temperatures[idx]递减可等
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!sk.empty() && temperatures[sk.top()] < temperatures[i]) {
                res[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return res;
    }
};
class Solution2 {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        for (int i = 0; i < temperatures.size(); ++i) {
            q.push(make_pair(temperatures[i], i));
        }
        vector<pair<int, int>> re{{2, 1}, {2, 2}, {3, 1}, {1, 1}};
        sort(re.begin(), re.end(), comp);

        while (!q.empty()) {
            cout << "topval: " << q.top().first << endl;
            q.pop();
        }
        for (int i = 0; i < re.size(); ++i) {
            cout << "re " << re[i].first << " " << re[i].second << endl;
        }
        // for (int i = 0; i < temperatures.size(); ++i) {
        //     while (!q.empty() && q.top().first < temperatures[i]) {
        //         res[q.top().second] = i - q.top().second;
        //         q.pop();
        //     }
        //     q.push(make_pair(temperatures[i], i));
        // }
        return res;
    }
};
int main() {
    Solution A;
    vector<int> num{73, 74, 75, 71, 69, 72, 76, 73};
    // 1,1,4,2,1,1,0,0
    show(A.dailyTemperatures(num));

    return 0;
}