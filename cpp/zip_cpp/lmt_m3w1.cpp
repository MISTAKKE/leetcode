#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
// 输入第一行仅包含三个正整数n,x,y，分别表示参赛的人数和晋级淘汰人数区间。(1<=n<=50000,1<=x,y<=n)
// 输入第二行包含n个整数，中间用空格隔开，表示从1号选手到n号选手的成绩。(1<=|a_i|<=1000)
int main() {
    int n, tmp, cnt;
    cin >> n;
    cnt = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        q.push(tmp);
    }
    for (int i = 1; i <= n; ++i) {
        cnt += abs(i - q.top());
        q.pop();
    }
    cout << cnt << endl;
    return 0;
}