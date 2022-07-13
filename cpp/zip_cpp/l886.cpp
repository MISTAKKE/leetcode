#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int defaultval{10000};
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<set<int>>> placed;
        vector<int> visited(n, defaultval);  // 10000 means not exists
        for (int i = 0; i < dislikes.size(); ++i) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            if (visited[a] == defaultval && visited[b] == defaultval) {
                placed.push_back({set<int>{a}, set<int>{b}});
                visited[a] = placed.size();
                visited[b] = placed.size() * -1;
            }
            else if (visited[a] != defaultval && visited[b] != defaultval) {
                if (visited[a] + visited[b] == 0) {
                    // case1 other room
                    continue;
                }
                else if (visited[a] == visited[b]) {
                    // case2 same room
                    return false;
                }
                else {  // case 3 diff room
                    // update visited
                    for (auto it : placed[abs(visited[b])][visited[b] > 0 ? 1 : 0]) {
                        visited[it] = visited[a];
                        placed[abs(visited[a])][visited[a] > 0 ? 0 : 1]
                    }
                    for (auto it : placed[abs(visited[b])][visited[b] > 0 ? 0 : 1]) {
                        visited[it] = visited[a] * -1;
                    }

                    // merge b to a

                    // remove vector
                }
            }
            else if (visited[a] != defaultval) {  // a is in placed
                visited[b] = visited[a] * -1;
                placed[abs(visited[b]) - 1][visited[b] > 0 ? 0 : 1].insert(b);
            }
            else {  // b is in placed
                visited[a] = visited[b] * -1;
                placed[abs(visited[a]) - 1][a > 0 ? 0 : 1].insert(a);
            }
        }
        return true;
    }
};

int main() {
    Solution A;

    return 0;
}
