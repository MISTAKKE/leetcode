#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; ++i) {
        vector<int> vec2;
        cin >> a;

        for (int j = 0; j < a; ++j) {
            cin >> b;
            vec2.push_back(b);
        }
        vec.push_back(vec2);
    }

    vector<string> res;
    for (int i = 0; i < n; ++i) {
        int pos = 0;
        int zero = 0;
        int neg = 0;
        for (int j = 0; j < vec[i].size(); ++j) {
            if (vec[i][j] > 0)
                pos += 1;
            else if (vec[i][j] == 0)
                zero += 1;
            else
                neg += 1;
        }
        if (pos == neg) {
            res.push_back("Yes");
            continue;
        }
        else if (pos > neg) {
            if (pos - neg - 1 <= zero) {
                res.push_back("Yes");
            }
            else {
                res.push_back("No");
            }
        }
        else {
            if (neg - pos - 1 <= zero) {
                res.push_back("Yes");
            }
            else {
                res.push_back("No");
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1)
            cout << endl;
    }

    return 0;
}
