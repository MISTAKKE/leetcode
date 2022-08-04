#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vec(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                vec[i] = vec[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                vec[i] = max(vec[i], vec[i + 1] + 1);
            }
        }
        show(vec);
        return accumulate(vec.begin(), vec.end(), 0);
    }
};

int main() {
    Solution A;
    vector<int> vec{1, 2, 2};
    cout << A.candy(vec) << endl;

    return 0;
}
