#include "../tool/helper.cpp"
using namespace std;
class Solution {
  public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        for (auto&& c : dislikes) {
            graph[c[0] - 1][c[1] - 1] = true;
            graph[c[1] - 1][c[0] - 1] = true;
        }
        vector<int> color(n, 0);  // 0 as init; other is 1 -1
        for (int i = 0; i < n; ++i) {
            if (color[i % n] == 0) {
                color[i % n] = 1;
            }
            if (!dfs(graph, color, i % n)) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<bool>>& graph, vector<int>& color, int idx) {
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[idx][i]) {
                if (color[i] == 0) {
                    color[i] = -1 * color[idx];
                    if (!dfs(graph, color, i)) {
                        return false;
                    }
                }
                else if (color[i] == color[idx]) {
                    return false;
                }
                else {
                    ;
                }
            }
        }
        return true;
    }
};
class Solution1 {
  public:
    int defaultval{10000};
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
                    int oldb = abs(visited[b]) - 1;
                    for (auto it : placed[abs(visited[b]) - 1][visited[b] > 0 ? 1 : 0]) {
                        visited[it] = visited[a];
                        placed[abs(visited[a]) - 1][visited[a] > 0 ? 0 : 1].insert(it);
                    }
                    for (auto it : placed[abs(visited[b]) - 1][visited[b] > 0 ? 0 : 1]) {
                        visited[it] = visited[a] * -1;
                        placed[abs(visited[a]) - 1][visited[a] > 0 ? 1 : 0].insert(it);
                    }
                }
            }
            else if (visited[a] != defaultval) {  // a is in placed
                visited[b] = visited[a] * -1;
                placed[abs(visited[b]) - 1][visited[b] > 0 ? 0 : 1].insert(b);
            }
            else {  // b is in placed
                visited[a] = visited[b] * -1;
                placed[abs(visited[a]) - 1][visited[a] > 0 ? 0 : 1].insert(a);
            }
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
    // vector<vector<int>> dislikes{{6, 9},  {1, 3},  {4, 8},  {5, 6}, {2, 8}, {4, 7},  {8, 9}, {2, 5},  {5, 8}, {1,
    // 2},
    //                              {6, 7},  {3, 10}, {8, 10}, {1, 5}, {3, 6}, {1, 10}, {7, 9}, {4, 10}, {7, 10},
    //                              {1, 4}, {9, 10}, {4, 6},  {2, 7},  {6, 8}, {5, 7}, {3, 8},  {1, 8}, {1, 7},  {7,
    //                              8}, {2, 4}};
    // cout << A.possibleBipartition(10, dislikes) << endl;
    // vector<vector<int>> dislikes{{4, 7}, {4, 8},  {5, 6},  {1, 6}, {3, 7},  {2, 5},  {5, 8}, {1, 2},
    //                              {4, 9}, {6, 10}, {8, 10}, {3, 6}, {2, 10}, {9, 10}, {3, 9}, {2, 3},
    //                              {1, 9}, {4, 6},  {5, 7},  {3, 8}, {1, 8},  {1, 7},  {2, 4}};
    vector<vector<int>> dislikes{
        {21, 47}, {4, 41},  {2, 41},  {36, 42}, {32, 45}, {26, 28}, {32, 44}, {5, 41},  {29, 44}, {10, 46}, {1, 6},
        {7, 42},  {46, 49}, {17, 46}, {32, 35}, {11, 48}, {37, 48}, {37, 43}, {8, 41},  {16, 22}, {41, 43}, {11, 27},
        {22, 44}, {22, 28}, {18, 37}, {5, 11},  {18, 46}, {22, 48}, {1, 17},  {2, 32},  {21, 37}, {7, 22},  {23, 41},
        {30, 39}, {6, 41},  {10, 22}, {36, 41}, {22, 25}, {1, 12},  {2, 11},  {45, 46}, {2, 22},  {1, 38},  {47, 50},
        {11, 15}, {2, 37},  {1, 43},  {30, 45}, {4, 32},  {28, 37}, {1, 21},  {23, 37}, {5, 37},  {29, 40}, {6, 42},
        {3, 11},  {40, 42}, {26, 49}, {41, 50}, {13, 41}, {20, 47}, {15, 26}, {47, 49}, {5, 30},  {4, 42},  {10, 30},
        {6, 29},  {20, 42}, {4, 37},  {28, 42}, {1, 16},  {8, 32},  {16, 29}, {31, 47}, {15, 47}, {1, 5},   {7, 37},
        {14, 47}, {30, 48}, {1, 10},  {26, 43}, {15, 46}, {42, 45}, {18, 42}, {25, 42}, {38, 41}, {32, 39}, {6, 30},
        {29, 33}, {34, 37}, {26, 38}, {3, 22},  {18, 47}, {42, 48}, {22, 49}, {26, 34}, {22, 36}, {29, 36}, {11, 25},
        {41, 44}, {6, 46},  {13, 22}, {11, 16}, {10, 37}, {42, 43}, {12, 32}, {1, 48},  {26, 40}, {22, 50}, {17, 26},
        {4, 22},  {11, 14}, {26, 39}, {7, 11},  {23, 26}, {1, 20},  {32, 33}, {30, 33}, {1, 25},  {2, 30},  {2, 46},
        {26, 45}, {47, 48}, {5, 29},  {3, 37},  {22, 34}, {20, 22}, {9, 47},  {1, 4},   {36, 46}, {30, 49}, {1, 9},
        {3, 26},  {25, 41}, {14, 29}, {1, 35},  {23, 42}, {21, 32}, {24, 46}, {3, 32},  {9, 42},  {33, 37}, {7, 30},
        {29, 45}, {27, 30}, {1, 7},   {33, 42}, {17, 47}, {12, 47}, {19, 41}, {3, 42},  {24, 26}, {20, 29}, {11, 23},
        {22, 40}, {9, 37},  {31, 32}, {23, 46}, {11, 38}, {27, 29}, {17, 37}, {23, 30}, {14, 42}, {28, 30}, {29, 31},
        {1, 8},   {1, 36},  {42, 50}, {21, 41}, {11, 18}, {39, 41}, {32, 34}, {6, 37},  {30, 38}, {21, 46}, {16, 37},
        {22, 24}, {17, 32}, {23, 29}, {3, 30},  {8, 30},  {41, 48}, {1, 39},  {8, 47},  {30, 44}, {9, 46},  {22, 45},
        {7, 26},  {35, 42}, {1, 27},  {17, 30}, {20, 46}, {18, 29}, {3, 29},  {4, 30},  {3, 46}};
    cout << A.possibleBipartition(50, dislikes) << endl;

    return 0;
}
