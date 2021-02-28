#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int getKthMagicNumber(int k)
    {
        vector<int> result(k, 0);
        result[0] = 1;
        // 定义三个 指针，分别表示 resultA、B、C 的下标
        int point3 = 0;
        int point5 = 0;
        int point7 = 0;
        for (int i = 1; i < k; i++)
        {
            int resultN = min(min(result[point3] * 3, result[point5] * 5), result[point7] * 7);
            if (resultN % 3 == 0)
            {
                point3++;
            }
            if (resultN % 5 == 0)
            {
                point5++;
            }
            if (resultN % 7 == 0)
            {
                point7++;
            }
            cout << "i:" << i << " point3:" << point3 << " point5:" << point5 << " point7:" << point7 << " resultN:"<<resultN<<endl;
            result[i] = resultN;
        }
        return result[k - 1];
    }
};

int main()
{
    Solution A;
    A.getKthMagicNumber(15);

    return 0;
}
