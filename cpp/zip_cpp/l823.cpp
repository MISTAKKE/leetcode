#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    long long mod = 1000000007;
    int findexist(int x, int right, vector<int>& A) {
        int left = 0, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == x) {
                return mid;
            }
            else if (A[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>());
        vector<long long> result(n, 1);
        int ret = 0;
        for (int i = 0; i < A.size(); ++i) {
            int existmin = A[i];
            for (int j = 0; j < i && A[j] < existmin; ++j) {
                if (A[i] % A[j] == 0) {
                    int findx = findexist(A[i] / A[j], i - 1, A);
                    if (findx != -1) {
                        existmin = A[i] / A[j];
                        p[i].push_back(make_pair(j, findx));
                    }
                }
            }
        }
        show(p);
        for (int i = 0; i < n; ++i) {
            if (p[i].size() != 0) {
                for (auto each : p[i]) {
                    int fac = 1;
                    if (each.first != each.second)
                        fac = 2;
                    cout << "i=" << i << " each=" << each << " fac=" << fac << endl;
                    result[i] = (result[i] + (result[each.first] * fac * result[each.second]) % mod) % mod;
                }
            }
            ret = (ret + result[i]) % mod;
        }
        show(result);
        return ret;
    }
};

int main() {
    Solution A;
    vector<int> nums{11, 22, 33, 34, 35};
    print(A.numFactoredBinaryTrees(nums));

    return 0;
}
