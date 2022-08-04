#include <iostream>
#include <vector>
using namespace std;

int f(string& str) {
    int n = 0;  // numbers of 0
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '0')
            n++;
    }
    int m = str.size() - n;  // numbers of 1
    if (n > m) {
        m = (n - m) / 2;
        n = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '0')
                n++;
            else
                n--;
            if (n == m) {
                return i + 1;
            }
        }
    }
    else if (m == n) {
        return str.size();
    }
    else {
        n = (m - n) / 2;  // 1
        m = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '1')
                m++;
            else
                m--;
            if (n == m) {
                return i + 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string str;
    vector<int> vec;
    while (n--) {
        cin >> str;
        vec.push_back(f(str));
    }
    for (int i = 0; i < vec.size(); ++i)
        cout << "1 " << vec[i] << endl;

    return 0;
}
