#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    string simplifyPath(string path) {
        stack<string> sk;
        string tmp = "";
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] != '/')  // other + doc
            {
                tmp += path[i];
            }
            else if (!tmp.empty())  // /
            {
                if (tmp == "..") {
                    if (!sk.empty()) {
                        sk.pop();
                    }
                }
                else if (tmp != ".") {
                    sk.push(tmp);
                }
                tmp = "";
            }
        }
        if (tmp == "..") {
            if (!sk.empty()) {
                sk.pop();
            }
        }
        else if (tmp != ".") {
            sk.push(tmp);
        }

        string ret = "";
        while (!sk.empty()) {
            if (!ret.empty()) {
                ret = sk.top() + "/" + ret;
            }
            else {
                ret = sk.top();
            }
            sk.pop();
        }
        ret = "/" + ret;
        return ret;
    }
};

int main() {
    Solution A;
    string str = "/.";
    // cout << A.simplifyPath(str) << endl;
    cout << sizeof(str) << endl;
    vector<int> vec;
    string s;
    cout << sizeof(s) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(vec) << endl;
    return 0;
}
