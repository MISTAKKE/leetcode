#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

1 <= s.length, t.length <= 10^5
s 和 t 由英文字母组成
*/

// Class Solution
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> window(26*2, 0);
        vector<int> vect(26*2, 0);
        for(int i = 0;i<t.size();++i){
            change(vect, t[i], 1);
        }
        
        int left = 0, right = 0;
        int minval = 100001, minleft = 0;
        // init window
        while(right<t.size()-1 && right < s.size()){
            change(window, s[right], 1);
            right += 1;
        }
        show(window);
        show(vect);

        while(right < s.size()){
            change(window, s[right], 1);
            right += 1;
            if(getfitflag(window, vect)){
                if(right - left < minval){
                    minleft = left;
                    minval = right - left;
                }
                change(window, s[left], -1);
                left += 1;
                while(getfitflag(window, vect) && (left < right)){
                    if(right - left < minval){
                        minleft = left;
                        minval = right - left;
                    }
                    change(window, s[left], -1);
                    left += 1;
                }
            }
        }

        if(minval == 100001){
            return "";
        }
        return s.substr(minleft, minval);
    }
    int getfitflag(vector<int> &window, vector<int> &vect){
        for(int i = 0;i<26*2;++i){
            if(window[i]<vect[i]){
                return false;
            }
        }
        return true;//means fit
    }
    void change(vector<int> &thevec, char &c, int direction){
        if(c >= 'a' && c <='z'){
            thevec[c-'a'] += direction;
        }
        else{
            thevec[c-'A'+26] += direction;
        }
    }
};
int main() {
    Solution A;
    string s = "ab";
    string t = "aaab";
    cout<<A.minWindow(s, t)<<endl;

    return 0;
}
