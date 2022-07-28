#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

// Class Solution
class Solution {
  public:
    int trap(vector<int>& height) {
        stack<int> sk;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!sk.empty() && height[sk.top()] < height[i]) {
                int popval = height[sk.top()];
                sk.pop();
                if (!sk.empty()) {
                    res += (min(height[sk.top()], height[i]) - popval) * (i - sk.top() - 1);
                }
            }
            sk.push(i);
        }
        return res;
    }
};

class Solution2 {
  public:
    int trap(vector<int>& height) {
        stack<int> sk;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            //为空的时候，入栈
            if (sk.empty()) {
                cout << "sk.empty()  i:" << i << " push" << endl;
                sk.push(i);
            }
            //栈顶大于当前值，入栈
            else if (height[i] <= height[sk.top()]) {
                cout << "now less top  i:" << i << " push" << endl;
                sk.push(i);
            }
            else {
                //栈顶小于当前值，出站并计算宽度
                while (!sk.empty() && height[sk.top()] < height[i]) {
                    int popval = height[sk.top()];
                    sk.pop();
                    cout << "popval:" << popval << " pop" << endl;
                    if (!sk.empty()) {
                        res += (min(height[sk.top()], height[i]) - popval) * (i - sk.top() - 1);
                        cout << "res+=: val:" << min(height[sk.top()], height[i]) - popval
                             << " width:" << (i - sk.top() - 1);
                    }
                }
                sk.push(i);
            }
        }
        return res;
    }
};
class Solution1 {
  public:
    int trap1(vector<int>& height) {
        vector<int> left(height.size(), height[0]);
        vector<int> right(height.size(), height.back());

        for (int i = 1; i < height.size(); ++i) {
            left[i] = max(left[i - 1], height[i]);
        }
        for (int i = height.size() - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            res += (min(left[i], right[i]) - height[i]);
        }
        return res;
    }
};

int main() {
    Solution A;
    // vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};//6
    vector<int> height{4, 2, 0, 3, 2, 5};  // 9
    cout << A.trap(height) << endl;

    return 0;
}
