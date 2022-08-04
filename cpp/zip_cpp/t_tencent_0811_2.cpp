#include <algorithm>  // std::sort
#include <iostream>
#include <vector>
using namespace std;

class people {
  public:
    int r;
    int c;
    int spr;
    int spc;
    people(int mr, int mc, int mspr, int mspc) : r(mr), c(mc), spr(mspr), spc(mspc){};
};
bool findmax(const people& p1, const people& p2) {
    return p1.r > p1.r;
}

vector<int> f() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> rev;
    vector<int> cost;
    vector<int> sprev;
    vector<int> spcost;
    for (int i = 0; i < n; ++i) {
        cin >> rev[i];
        cin >> cost[i];
        cin >> sprev[i];
        cin >> spcost[i];
    }
    int revmax = 0;
    int costmin = 0;
    vector<vector<int>> ret;
    for (int i = 0; i < n; ++i) {
        //第i个为sp
        //其他的n-1个人里面得到m-1个
        vector<people> thisrev;
        for (int j = 0; j < n; ++j) {
            if (j != i)
                thisrev.push_back(people(rev[i], cost[i], sprev[i], spcost[i]));
            sort(thisrev.begin(), thisrev.end(), findmax);
            for (int k = 0; k < m - 1; ++k) {
                revmax += thisrev[i].r;
            }
            revmax += rev[i];
        }
    }

    return vector<int>{revmax, costmin};
}

int main() {
    int n;
    cin >> n;
    string str;
    vector<vector<int>> vec;
    while (n--) {
        vec.push_back(f());
    }
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i][0] << " " << vec[i][1] << endl;

    return 0;
}
