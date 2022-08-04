#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<int> fairCandySwap1(vector<int> A, vector<int> B) {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int diff = (suma - sumb) / 2;  //  A:1 3   B:2
        set<int> se(A.begin(), A.end());
        int flag = (suma > sumb) * 2 - 1;
        for (auto b : B) {
            if (se.count(b + diff) == 1) {
                return {b + diff, b};
            }
        }
        return A;
    }
    vector<int> fairCandySwap(vector<int> A, vector<int> B) {
        sort(A.begin(), A.end(), less<int>());
        sort(B.begin(), B.end(), less<int>());
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int diff = (suma - sumb) / 2;  //  A:1 3   B:2
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] - diff == B[j]) {
                return {A[i], B[j]};
            }
            else if (A[i] - diff > B[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        return A;
    }
};

int main() {
    Solution A;
    show(A.fairCandySwap({2}, {1, 3}));
    show(A.fairCandySwap({1, 3}, {2}));
    return 0;
}
