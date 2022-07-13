#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int defaultval{10000};
    void display(vector<vector<set<int>>>& placed) {
        cout << "一共有" << placed.size() << "组数据" << endl;
        for (int i = 0; i < placed.size(); ++i) {
            show(placed[i][0]);
            show(placed[i][1]);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<set<int>>> placed;
        vector<int> visited(n + 1, defaultval);  // 10000 means not exists
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
                    // merge b to a
                    for (auto it : placed[abs(visited[b] - 1)][visited[b] > 0 ? 1 : 0]) {
                        visited[it] = visited[a];
                        placed[abs(visited[a]) - 1][visited[a] > 0 ? 0 : 1].insert(it);
                    }
                    for (auto it : placed[abs(visited[b])][visited[b] > 0 ? 0 : 1]) {
                        visited[it] = visited[a] * -1;
                        placed[abs(visited[a]) - 1][visited[a] > 0 ? 1 : 0].insert(it);
                    }

                    // remove vector
                    placed.erase(placed.begin() + abs(visited[b]));
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
            // display(placed);
        }
        return true;
    }
};

int main() {
    Solution A;
    // vector<vector<int>> dislikes{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    // cout << A.possibleBipartition(5, dislikes) << endl;
    // vector<vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};
    // cout << A.possibleBipartition(4, dislikes) << endl;
    vector<vector<int>> dislikes{{6, 9},  {1, 3},  {4, 8},  {5, 6}, {2, 8}, {4, 7},  {8, 9}, {2, 5},  {5, 8},  {1, 2},
                                 {6, 7},  {3, 10}, {8, 10}, {1, 5}, {3, 6}, {1, 10}, {7, 9}, {4, 10}, {7, 10}, {1, 4},
                                 {9, 10}, {4, 6},  {2, 7},  {6, 8}, {5, 7}, {3, 8},  {1, 8}, {1, 7},  {7, 8},  {2, 4}};
    cout << A.possibleBipartition(10, dislikes) << endl;

    return 0;
}
