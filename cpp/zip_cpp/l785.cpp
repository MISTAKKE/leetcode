#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int n;
    vector<bool> processed;
    bool white = true;
    queue<int> q;
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        if (n <= 1)
            return true;
        for (int i = 0; i < n; ++i) {
            processed.push_back(false);
        }
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() != 0 && processed[i] == false) {
                if (!bfs(i, graph))
                    return false;
            }
        }
        return true;
    }

    bool bfs(int i, vector<vector<int>>& graph) {
        vector<int> color(n, 0);
        q.push(i);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int t = q.front();
                q.pop();
                processed[t] = true;  // set has done
                color[t] = white;     // set t as white
                for (int i = 0; i < graph[t].size(); ++i) {
                    int neighbor = graph[t][i];
                    if (color[neighbor] != white)
                        color[neighbor] = !white;  // set each t neighbor as black
                    else
                        return false;
                    if (!processed[neighbor])
                        q.push(neighbor);
                }
            }
            white = !white;
        }
        return true;
    }
};

int main() {
    Solution A;

    // vector<vector<int>>num
    // {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    // vector<vector<int>>num {{1,3},{0,2},{1,3},{0,2}};
    vector<vector<int>> num{{2, 4},   {2, 3, 4},    {0, 1},       {1},          {0, 1},
                            {7},      {9},          {5},          {},           {6},
                            {12, 14}, {},           {10},         {},           {10},
                            {19},     {18},         {},           {16},         {15},
                            {23},     {23},         {},           {20, 21},     {},
                            {},       {27},         {26},         {},           {},
                            {34},     {33, 34},     {},           {31},         {30, 31},
                            {38, 39}, {37, 38, 39}, {36},         {35, 36},     {35, 36},
                            {43},     {},           {},           {40},         {},
                            {49},     {47, 48, 49}, {46, 48, 49}, {46, 47, 49}, {45, 46, 47, 48}};
    print(A.isBipartite(num));

    return 0;
}
