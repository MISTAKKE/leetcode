#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> mp;
        for (auto tick : tickets) {
            mp[tick[0]].push(tick[1]);
        }
        vector<string> ret;
        string now = "JFK";
        int cnt = tickets.size();
        ret.push_back(now);
        while (cnt > 0) {
            cnt--;
            string top = mp[now].top();
            if (cnt != 0) {
                vector<string> tmp = {};
                while (mp[top].size() == 0) {
                    tmp.push_back(top);
                    mp[now].pop();
                    top = mp[now].top();
                }
                for (auto i : tmp) {
                    mp[now].push(i);
                }
            }
            mp[now].pop();
            now = top;
            ret.push_back(now);
            show(ret);
        }

        return ret;
    }
};
int main() {
    Solution A;
    vector<vector<string>> tickets{{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    show(A.findItinerary(tickets));

    return 0;
}
