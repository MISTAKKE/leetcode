#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int minArray1(vector<int>& numbers) {
        int qmin = numbers[0];
        for(int i = 0; i<numbers.size(); ++i)
            qmin = min(qmin, numbers[i]);
        return qmin;
    }
    int minArray2(vector<int>& numbers){
        if(numbers.size() ==1) return numbers[0];
        for(int i =1;i<numbers.size(); ++i)
            if(numbers[i] < numbers[i-1])
                return numbers[i];
        return numbers[0];
    }
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1, mid;
        while(left<right)
        {
            mid = left + (right-left)/2;
            if(numbers[mid] < numbers[right])
                right = mid;
            else if(numbers[mid] > numbers[right])
                left = mid+1;
            else
                right -=1;
        }
        return numbers[left];
    }
};

int main()
{
    Solution A;    
    vector<int> numbers {2,3,4,5,6,7,0,1};
    show(numbers);
    print(A.minArray(numbers), 4);

    return 0;
}
