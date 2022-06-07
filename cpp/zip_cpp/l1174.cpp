#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1147. 段式回文
你会得到一个字符串 text 。你应该把它分成 k 个子字符串 (subtext1, subtext2，…， subtextk) ，要求满足:
subtexti 是非空字符串
所有子字符串的连接等于 text ( 即subtext1 + subtext2 + ... + subtextk == text )
subtexti == subtextk - i + 1 表示所有 i 的有效值( 即 1 <= i <= k )
返回k可能最大值。

示例 1：
输入：text = "ghiabcdefhelloadamhelloabcdefghi"
输出：7
解释：我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。

示例 2：
输入：text = "merchant"
输出：1
解释：我们可以把字符串拆分成 "(merchant)"。

示例 3：
输入：text = "antaprezatepzapreanta"
输出：11
解释：我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。

示例 4：
输入：text = "aaa"
输出：3
解释：我们可以把字符串拆分成 "(a)(a)(a)"。

提示：
1 <= text.length <= 1000
text 仅由小写英文字符组成
*/

// Class Solution
class Solution {
  public:
    int longestDecomposition(string text) {
        for (int i = 1; i <= text.size() / 2; ++i) {
            if (text.substr(0, i) == text.substr(text.size() - i, i)) {
                return 2 + longestDecomposition(text.substr(i, text.size() - 2 * i));
            }
        }
        return text.size() >= 1 ? 1 : 0;
    }
};
int main() {
    Solution A;
    std::string str = "antaprezatepzapreanta";
    cout << A.longestDecomposition(str) << endl;
    return 0;
}
