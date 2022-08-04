#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<int> findNumOfValidWords(vector<string>& w, vector<string>& p) {
        unordered_map<int, int> hash;  //用map将string转为int, 而不是用vector将string转为int  前者可将相同的string降低
        int n = w.size(), m = p.size();
        vector<int> ans(m);
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (char c : w[i])
                t |= (1 << c - 'a');
            hash[t]++;
        }

        for (int i = 0; i < m; i++) {
            int k = 0;              // k为第i个puzzle的值
            int t = p[i][0] - 'a';  // t是第i个puzzle的首字母
            for (char c : p[i])
                k |= (1 << c - 'a');
            for (int j = k; j != 0;
                 j = (j - 1) &
                     k)  // j=j-1 代表不停尝试更小的j，& 表示只care在pullze中有的；这是一个单调递减的，所以终止为j>0
                if (j >> t & 1)  // j右移t位后，就是上面puzzle的第一位，& 表示其是否存在
                    ans[i] += hash[j];
        }

        return ans;
    }

    vector<int> findNumOfValidWords_old(vector<string>& words, vector<string>& puzzles) {
        vector<int> res(puzzles.size(), 0);

        vector<int> wordshash(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto&& c : words[i]) {
                wordshash[i] |= (1 << c - 'a');
            }
        }

        vector<int> num(puzzles.size(), 0);
        for (int i = 0; i < puzzles.size(); ++i) {
            for (auto&& c : puzzles[i]) {
                num[i] |= (1 << c - 'a');
            }
        }

        vector<bool> midipossible(puzzles.size(), true);
        for (int i = 0; i < wordshash.size(); ++i) {
            // check某一个单词，是否是 每个puzzle的谜底
            for (int j = 0; j < puzzles.size(); ++j) {
                midipossible[j] = true;
                int first = puzzles[j][0] - 'a';
                if (!(wordshash[i] & (1 << first))) {
                    midipossible[j] = false;
                }
            }

            for (int k = 0; k < 26; ++k) {
                if ((wordshash[i] & (1 << k)) != 0)  // word有k
                {
                    for (int j = 0; j < puzzles.size(); ++j) {
                        if (midipossible[j] && !(num[j] & (1 << k)))  // puzzle[j] 无 k
                        {
                            midipossible[j] = false;
                        }
                    }
                }
            }

            for (int j = 0; j < puzzles.size(); ++j) {
                res[j] += midipossible[j];
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    // vector<string> words{"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    // vector<string> puzzles{"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    // //输出：[1,1,3,2,4,0]

    vector<string> words{"aebd",
                         "cbdjegehgfcefbgceifdcjcbhdbbhhdi",
                         "bbcaehdgdghgaaghdbdg",
                         "fhgjegdagiadgdhaeicgjgifabadjdfe",
                         "gcadacg",
                         "efhjdffcaih",
                         "cgfjcdddabcdafjhcafieiadgebdeicbjjifgjbaf",
                         "cbfhbdaiajhdefgjefjibefjaahgdachhfge",
                         "cjejijcibgigceefidhcgbbdgg",
                         "jaedgdggbajbbibifadjeddbff",
                         "chdihgafjgfeaeefdigfeifjaihcg",
                         "giicgbjeah",
                         "bagcfechdabicgbidbceggjfedaabfibhcieefjhj",
                         "gbagbjhdjjdgifgaciehfjabi",
                         "ehheaajfbjdhabbjafeid",
                         "biajeeagdecjigefgidc",
                         "fejfdfeghbbdfc",
                         "bfbfffe",
                         "digd",
                         "bciabjhf"};
    vector<string> puzzles{"axtniqf", "xsdlyik", "ldsimca", "ptvdamy", "djihgak",
                           "xencovd", "rbwpugz", "xvsbpmj", "epfhmxs", "fshonmc"};
    show(A.findNumOfValidWords(words, puzzles));

    return 0;
}
