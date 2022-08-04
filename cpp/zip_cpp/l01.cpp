#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    bool isUnique(string str) {
        int b = 0;
        for (int i = 0; i < str.size(); ++i) {
            int fix = 1 << (str[i] - 'a');
            if (b & fix)
                return false;
            b = b + fix;
            print("b:", b);
        }
        return true;
    }
};

int main() {
    Solution A;
    print(A.isUnique("agbcdefg"));

    return 0;
}
