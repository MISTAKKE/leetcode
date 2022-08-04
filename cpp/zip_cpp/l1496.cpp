#include "../tool/helper.cpp"
using namespace std;

class Solution {
  public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s;
        map<char, int> m;
        m['N'] = 2 + 1 * 4;
        m['S'] = 2 + 3 * 4;
        m['E'] = 1 + 2 * 4;
        m['W'] = 3 + 2 * 4;
        int nowi = 0;
        int nowj = 0;
        s.insert(make_pair(nowi, nowj));
        for (int i = 0; i < path.size(); ++i) {
            nowi += 2 - m[path[i]] % 4;
            nowj += 2 - m[path[i]] / 4;
            pair<int, int> p(nowi, nowj);
            print(p);
            if (find(s.begin(), s.end(), p) != s.end())
                return true;
            s.insert(p);
        }

        return false;
    }
};

int main() {
    Solution A;
    print(A.isPathCrossing("NNSWWEWSSESSWENNW"));

    return 0;
}
