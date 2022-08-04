#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ret = 0;
        int dx = 0;
        int dy = 0;
        int direction = 0;  //   0:up  1:left  2:down  3:right
        vector<int> px{0, 1, 0, -1};
        vector<int> py{1, 0, -1, 0};
        set<int> block;
        for (auto obs : obstacles) {
            block.insert(obs[0] * 4 * 10000 + obs[1]);
        }
        for (auto command : commands) {
            if (command > 0) {
                int dxx = dx;
                int dyy = dy;
                for (int i = 0; i < command; ++i) {
                    dxx += px[direction];
                    dyy += py[direction];
                    if (block.find(dxx * 4 * 10000 + dyy) != block.end()) {
                        dxx -= px[direction];
                        dyy -= py[direction];
                        break;
                    }
                }
                ret = max(ret, dxx * dxx + dyy * dyy);
                dx = dxx;
                dy = dyy;
            }
            else if (command == -1) {
                direction = (direction + 1) % 4;
            }
            else {
                direction = (direction + 3) % 4;
            }
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<int> commands{4, -1, 3};
    vector<vector<int>> obstacles;
    cout << A.robotSim(commands, obstacles) << endl;

    return 0;
}
