#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long sum = 0;
        int maxval = 0;
        for(int i = 0; i<n; ++i)
        {
            maxval = max(maxval, nums[i]);
            sum +=nums[i];
        }
        int left = maxval, right = sum;
        while(left < right)
        {
            int mid = (right + left)/2;
            if(check(nums, mid) > m)//not ok, mid is too small
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return left;
    }

    int check(vector<int>& nums, int maxval)
    {
        //return size of parts that each part not more than sum
        int cnt = 0;
        int val = 0;
        for(int i = 0; i<nums.size(); ++i)
        {
            if(maxval < val + nums[i])
            {
                val = nums[i];
                cnt +=1;
            }
            else
                val +=nums[i];
        }
        if(val !=0)
            cnt +=1;
        return cnt;
    }
    int splitArray2(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long>sum(n+1, 0);
        for(int i = 0; i<n; ++i)
        {
            sum[i+1] = sum[i] + nums[i];
        }
        show(sum);
        vector<vector<long long>> f(n+1, vector<long long>(m+1, sum[n]));//f[i][j] = split i number into j parts, min(max parts)
        f[0][0] = 0;
        for(int i =1; i<=n; ++i)
        {
            for(int j =1; j<=min(m, i); ++j)
            {
                for(int k =0; k<i; ++k)
                {
                    f[i][j] = min(f[i][j] , max(f[k][j-1], sum[i] - sum[k]));    
                }
            }
        }

        return f[n][m];
    }
};

int main()
{
    Solution A;    
    vector<int> nums{7,2,5,10,8};
    print(A.splitArray(nums,2));

    return 0;
}
