#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    int matrixScore(vector<vector<int>>& A) {
        int ret = 0;
        int n = A.size();     // 1 <= A.length <= 20
        int m = A[0].size();  // 1 <= A[0].length <= 20
        vector<int> vec(20, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vec[i] += A[j][i] ^ A[j][0];
            }
            cout << "i:" << i << " vec[i]:" << vec[i] << " max(vec[i], n - vec[i]):" << max(vec[i], n - vec[i]) << endl;
            vec[i] = max(vec[i], n - vec[i]);
            ret += pow(2, m - i - 1) * vec[i];
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<vector<int>> vec{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    cout << A.matrixScore(vec) << endl;

    return 0;
}
