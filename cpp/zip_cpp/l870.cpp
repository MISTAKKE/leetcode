#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> ret;
        sort(A.begin(), A.end());
        for (auto &i : B)
        {
            auto &&idx = lower_bound(A.begin(), A.end(), i + 1);
            {
                if (idx == A.end())
                {
                    idx = A.begin();
                }
                ret.push_back(*idx);
                A.erase(idx);
            }
        }
        return ret;
    }
};

int main()
{
    Solution A;
    vector<int> vec{12,24,8,32};
    vector<int> vec2{13,25,32,11};
    show(A.advantageCount(vec, vec2));

    return 0;
}
