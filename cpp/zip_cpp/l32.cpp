#include "../tool/helper.cpp"
using namespace std;

/*
description:
1. 用栈保存 左括号 以及 匹配好的数字
2. 利用括号的对称性 两遍遍历将异常的位置标出
3. 动态规划 dp[i] 为 i结尾的最长串长度 
    dp[i] 与 dp[i-i] 有关，i-1组成的最长的串的前面一个字符如果是( 且i为) 那么dp[i]就可延展

*/

class Solution1 //
/*
    1. 栈内如  0 k 0 k 0 k
    2. 单个 ( 用0   
    3. 匹配好的串()用数字
    4. 注意最多合并一次
*/
{
public:
    int longestValidParentheses(string s)
    {
        int maxval = 0;
        int leftcnt = 0;
        stack<int> st;
        for (auto &&c : s)
        {
            if (c == '(')
            {
                leftcnt += 1;
                st.push(0);
            }
            else //右括号来了
            {
                if (leftcnt > 0) //栈内有(
                {
                    // 2 0 2 0 2 0  t=2      come )
                    int t = st.top();
                    if (t != 0)
                    {
                        st.pop(); //pop num
                    }
                    st.pop(); //pop 0
                    leftcnt -= 1;
                    //try merge t to before num
                    if (!st.empty() && st.top() > 0)
                    {
                        t += st.top();
                        st.pop(); //pop before num
                    }
                    st.push(t + 2);
                    maxval = max(maxval, t + 2);
                }
                else
                {
                    if (!st.empty()) //栈内没有( 但是来了) 需要清空栈内数字
                    {
                        st.pop();
                    }
                }
            }
        }
        return maxval;
    }
};

class Solution2 //
/*
    1. 0000000
    2. 从左到右扫描 将error置为1
    3. 从右到左扫描 将error置为1
    4. 计算
*/
{
public:
    int longestValidParentheses(string s)
    {
        int val = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                val += 1;
            else
            {
                if (val == 0)
                    s[i] = ' ';
                else
                    val -= 1;
            }
        }
        val = 0;
        int cnt = 0;
        int maxcnt = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ')')
                val += 1;
            else if (s[i] == '(')
            {
                if (val == 0)
                {
                    maxcnt = max(maxcnt, cnt);
                    cnt = 0;
                    s[i] = ' ';
                }
                else
                {
                    val -= 1;
                    cnt += 2;
                }
            }
            else
            {
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
        }
        return max(maxcnt, cnt);
    }
};

class Solution //
/*
    1. 动态规划，dp[i]为i结尾的最长cnt
*/
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size(), 0);
        int maxval = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')')
            {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s[pre] == '(')
                {
                    dp[i] = dp[i - 1] + 2; //  ((()))
                    if (pre > 0)
                    {
                        dp[i] += dp[pre - 1];
                    }
                    maxval = max(maxval, dp[i]);
                }
            }
        }
        return maxval;
    }
};

int main()
{
    Solution A;
    cout << A.longestValidParentheses("())()()))") << endl;
    cout << A.longestValidParentheses("((())))") << endl;

    return 0;
}
