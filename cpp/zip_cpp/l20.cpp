#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            print("s[i]:", s[i]);
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;
                char c = st.top();
                st.pop();
                if (c == '(' && s[i] == ')' || c == '{' && s[i] == '}' || c == '[' && s[i] == ']') {
                    continue;
                }
                return false;
            }
            show(st);
        }
        return true;
    }
};

int main() {
    Solution A;
    string str = "()[]{}";
    print(A.isValid(str));
    return 0;
}
