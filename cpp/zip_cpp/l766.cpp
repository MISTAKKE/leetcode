#include "../tool/helper.cpp"
using namespace std;

/*
description:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99

*/

//Class Solution
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int lineidx = 0; lineidx < matrix.size() - 1; ++lineidx)
        {
            for (int j = 0; j < matrix[0].size() - 1; ++j)
            {
                if (matrix[lineidx][j] != matrix[lineidx + 1][j + 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution A;
    vector<vector<int>> vec{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    cout << A.isToeplitzMatrix(vec) << endl;

    return 0;
}
