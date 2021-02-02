#include "../tool/helper.cpp"
using namespace std;

/*
description:

    // 维护 o(k)的结构，支持 insert delete fingmid 操作
    // 暴力思路 每次排序  时间复杂度=k*logk*n排序 + n*logk查找 = k*n*logk 空间复杂度=o(k)
    // 优化1 第一次排序，后面每个数字仅 logk插入和delete和查找   时间复杂度=n*logk + k*logk = n*logk 空间复杂度=o(k)
    // 优化2 官方思路 优先队列维护数据 空间复杂度 o(n)；时间复杂度=n*logn 空间复杂度=o(n)
    // 优化3 不适用延时删除来删数据， 优先队列有没有用堆的方式进行insert 和 delete?  时间空间复杂度 同优化1
    // 优化4 用multiset维护 insert delete 
*/

//Class Solution
class Solution
{
public:
    vector<double> medianSlidingWindow_force(vector<int> &nums, int k)
    {
        // (window[(k-1)/2] + window[(k)/2])/2
        // 9: 0 1 2 3 [4] 5 6 7 8
        // 8: 0 1 2 [3 4] 5 6 7
        vector<double> ans;
        for (int i = 0; i <= nums.size() - k; ++i)
        {
            vector<int> window(nums.begin() + i, nums.begin() + k + i);
            sort(window.begin(), window.end(), less<int>());
            ans.push_back((1.0 * window[(k - 1) / 2] + 1.0 * window[(k) / 2]) / 2.0);
        }
        return ans;
    }

    vector<double> medianSlidingWindow_way1(vector<int> &nums, int k)
    {
        // (window[(k-1)/2] + window[(k)/2])/2
        // 9: 0 1 2 3 [4] 5 6 7 8
        // 8: 0 1 2 [3 4] 5 6 7
        vector<int> window(nums.begin(), nums.begin() + k);
        sort(window.begin(), window.end(), less<int>());
        vector<double> ans;
        ans.push_back((1.0 * window[(k - 1) / 2] + 1.0 * window[(k) / 2]) / 2.0);
        for (int i = k; i < nums.size(); ++i)
        {
            //insert i     remove i-k  and     let window sorted
            adjust(window, nums[i], nums[i - k]);
            //sort(window.begin(), window.end(), less<int>());
            ans.push_back((1.0 * window[(k - 1) / 2] + 1.0 * window[(k) / 2]) / 2.0);
        }
        return ans;
    }
    void adjust(vector<int> &nums, int insertval, int removeval)
    {
        int insertidx = lower_bound(nums.begin(), nums.end(), insertval) - nums.begin(); //to find idx
        int removeidx = lower_bound(nums.begin(), nums.end(), removeval) - nums.begin(); //must finded
        //cout<<"insertidx:"<<insertidx<<" removeidx:"<<removeidx<<endl;
        //cout<<"insertval:"<<insertval<<" removeval:"<<removeval<<endl;
        if (insertidx < removeidx)
        {
            //  0 1 3 5 7 9 11 13    //remove 9  insert 4   insertidx = 3   removeidx = 5
            //  0 1 3 4 5 7 11 13  move and set
            for (int i = removeidx; i > insertidx; --i)
            {
                nums[i] = nums[i - 1];
            }
            nums[insertidx] = insertval;
        }
        else if (insertidx > removeidx)
        {
            //  0 1 3 5 7 9 11 13    //remove 3  insert 8   insertidx = 4   removeidx = 2
            //  0 1 5 7 8 9 11 13  move and set
            for (int i = removeidx; i < insertidx - 1; ++i)
            {
                nums[i] = nums[i + 1];
            }
            nums[insertidx - 1] = insertval;
        }
        else
        {
            //  0 1 3 5 7 9 11 13    //remove 3  insert 4   insertidx = 2   removeidx = 2
            //  0 1 4 5 7 9 11 13  replace
            nums[removeidx] = insertval;
        }
    }

    vector<double> medianSlidingWindow_way4(vector<int> &nums, int k)
    {
        multiset<int> st; // 减少排序时间
        int len = nums.size();
        int left = 0, right = 0;
        vector<double> ret;
        while (right < len)
        {
            st.insert(nums[right]);
            if (st.size() > k)
            {
                st.erase(st.lower_bound(nums[left]));
                left++;
            }
            if (st.size() == k)
            {
                double t;
                if (k % 2 != 0)
                { // k 为奇数时，直接取multiset的中间值
                    t = (double)(*next(st.begin(), k / 2));
                }
                else
                { // k 为偶数时，直接取multiset的俩中间值的平均值
                    t = ((double)(*next(st.begin(), k / 2)) + (double)(*next(st.begin(), k / 2 - 1))) / 2;
                }
                ret.emplace_back(t);
            }
            right++;
        }

        return ret;
    }
};

int main()
{
    Solution A;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    show(A.medianSlidingWindow(nums, 3));

    //vector<int> nums{1,4,2,3};
    //show(A.medianSlidingWindow(nums, 2));

    //vector<int> nums{22, 22};
    //show(A.medianSlidingWindow(nums, 2));

    return 0;
}
