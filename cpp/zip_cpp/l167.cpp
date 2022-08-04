#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target || i >= j) {
            if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return vector<int>{i, j};
    }
};

int main() {
    Solution A;
    vector<int> numbers{2, 7, 11, 15};
    show(A.twoSum(numbers, 9));

    return 0;
}
