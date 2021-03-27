#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    int mintime(vector<int> num, int k)
    {
        //num 代表了木头的数目和长度，将他们切割成k个大小一个的木头，大小一样的木头最长有多长
        if (num.size() == 0)
            return 0;
        int maxlen = num[0];
        for (int i = 0; i < num.size(); ++i)
        {
            maxlen = max(maxlen, num[i]);
        }
        int l = 1, r = maxlen;
        while (l <= r)
        {
            int mid = l + (r - l) >> 1;
            if (check(num, mid, k))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
    int check(vector<int> &num, int size, int k)
    {
        int cnt = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            cnt += num[i] / size;
        }
        return cnt >= k;
    }
    int lower_bound(vector<int> &num, int start, int end, int val)
    {
        //from [start, end) find the first idx that num[idx] >= val
        while (start < end) //1 end is not accessed
        {
            int mid = start + (end - start) / 2; //2 overflow
            if (num[mid] < val)                  //3 stl only has <
            {
                start = mid + 1;
            }
            else
            {
                end = mid; //4 end is not sub
            }
        }
        return start;
    }
    int upper_bound(vector<int> &num, int start, int end, int val)
    {
        //from [start, end) find the first idx that num[idx] > val
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (!(val < num[mid]))
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }
};

int main()
{
    Solution A;
    vector<int> num{1, 2, 3, 4, 6, 6, 7, 8};
    cout << A.lower_bound(num, 0, num.size(), 5) << endl;
    cout << A.upper_bound(num, 0, num.size(), 5) << endl;

    return 0;
}
