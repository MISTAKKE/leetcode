#include "../tool/helper.cpp"
using namespace std;

class Solution2 {
  public:
    vector<vector<int>> num;
    vector<int> visited;
    bool dfs(int i) {
        if (visited[i] == 1)
            return false;
        if (visited[i] == -1)
            return true;
        visited[i] = 1;
        for (int k = 0; k < visited.size(); ++k) {
            if (num[i][k] == 0)
                continue;
            if (visited[k] == 1)
                return false;
            if (!dfs(k))
                return false;
        }
        visited[i] = -1;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < n; ++i) {
            num.push_back(vector<int>(n, 0));
            visited.push_back(0);
        }
        for (int i = 0; i < prerequisites.size(); ++i) {
            int b = prerequisites[i][0];
            int a = prerequisites[i][1];
            num[a][b] = 1;
        }
        show(num);
        if (!dfs(i))
            return false;

        return true;
    }
    int main() {
        return 0;
    }
};
