#include "../tool/helper.cpp"
using namespace std;

/*
description:

*/

// Class Solution
class Solution {
  public:
    vector<int> addToArrayForm1(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int idx = 0;
        int add = 0;
        show(A);
        while (K != 0 || add != 0) {
            if (A.size() <= idx)
                break;
            A[idx] = add + A[idx] + K % 10;
            add = A[idx] / 10;
            K = K / 10;
            A[idx] = A[idx] % 10;
            idx++;
        }  // K == 0  ||  A.size() == idx
        show(A);
        cout << "K:" << K << " add:" << add << endl;
        while (K != 0 || add != 0) {
            int p = K % 10 + add;
            A.push_back(p % 10);
            add = p / 10;
            K = K / 10;
        }
        show(A);
        reverse(A.begin(), A.end());
        return A;
    }

    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int idx = 0;
        int add = 0;
        bool flag = false;
        show(A);
        while (K != 0 || add != 0) {
            if (A.size() <= idx || flag) {
                flag = true;
                cout << "f(A.size()<=idx)" << endl;
                cout << "K:" << K << " add:" << add << endl;
                show(A);
                int p = K % 10 + add;
                A.push_back(p % 10);
                add = p / 10;
                K = K / 10;
                cout << "K:" << K << " add:" << add << endl;
                continue;
            }
            A[idx] = add + A[idx] + K % 10;
            add = A[idx] / 10;
            K = K / 10;
            A[idx] = A[idx] % 10;
            idx++;
        }
        show(A);
        reverse(A.begin(), A.end());
        return A;
    }
};
int main() {
    Solution A;
    vector<int> nums{0};
    int k = 10000;
    // vector<int>nums{0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    show(nums);
    show(A.addToArrayForm(nums, k));

    return 0;
}
