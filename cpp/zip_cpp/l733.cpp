#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    int newc;
    int oldc;
    vector<int> dx;
    vector<int> dy;
    vector<vector<bool>> visited;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0 || image[0].size() == 0)
            return image;
        newc = newColor;
        oldc = image[sr][sc];
        dx.resize(4);
        dx[0] = 0;
        dx[1] = -1;
        dx[2] = 0;
        dx[3] = 1;
        dy.resize(4);
        dy[0] = 1;
        dy[1] = 0;
        dy[2] = -1;
        dy[3] = 0;
        for (int i = 0; i < image.size(); ++i) {
            visited.push_back(vector<bool>(image[0].size(), false));
        }
        show(image);
        dfs(image, sr, sc);
        show(image);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc) {
        show(visited);
        image[sr][sc] = newc;
        visited[sr][sc] = true;
        for (int i = 0; i < 4; ++i) {
            if (isvalid(image, dx[i] + sr, dy[i] + sc))
                if (visited[dx[i] + sr][dy[i] + sc] == false)
                    dfs(image, dx[i] + sr, dy[i] + sc);
        }
    }
    bool isvalid(vector<vector<int>>& image, int sr, int sc) {
        if (sr >= 0 && sc >= 0 && sr < image.size() && sc < image[0].size())
            return image[sr][sc] == oldc;
        return false;
    }
};

int main() {
    Solution A;
    vector<vector<int>> res{{1, 1, 1}, {1, 2, 0}, {1, 0, 1}};
    A.floodFill(res, 1, 1, 2);
    return 0;
}
