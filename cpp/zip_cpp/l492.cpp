#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<int> constructRectangle1(int area) {
        int w = 1;
        int l = area;
        int tmp = w;
        while (tmp < l) {
            tmp++;
            if (area % tmp == 0) {
                l = area / tmp;
                w = tmp;
                if (l < w) {
                    tmp = l;
                    l = w;
                    w = tmp;
                    break;
                }
            }
        }
        return vector<int>{l, w};
    }

    vector<int> constructRectangle(int area) {
        int h = sqrt(area);
        while (area % h != 0)
            h--;
        return vector<int>{area / h, h};
    }
};

int main() {
    Solution A;
    show(A.constructRectangle1(4000));

    return 0;
}
