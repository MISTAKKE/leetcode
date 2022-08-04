#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution1 {
  public:
    string find(map<string, string>& fathermp, string a) {
        while (a != fathermp[a]) {
            a = fathermp[a];
        }
        return a;
    }
    double findval(map<string, string>& fathermp, map<string, double>& markval, string a, string b) {
        if (fathermp.find(a) == fathermp.end() || fathermp.find(b) == fathermp.end() ||
            find(fathermp, a) != find(fathermp, b)) {
            return -1;
        }
        return markval[a] / markval[b];
    }

    void merge(map<string, string>& fathermp, map<string, double>& markval, string father, string son, double val) {
        if (fathermp.find(father) == fathermp.end() && fathermp.find(son) == fathermp.end()) {
            // cout<<"1 father:"<<father<<" son:"<<son<<endl;
            //父子都是新的，对子、父赋值
            fathermp[son] = father;
            markval[son] = 1;
            fathermp[father] = father;
            markval[father] = val;
        }
        else if (fathermp.find(father) != fathermp.end() && fathermp.find(son) == fathermp.end()) {
            // cout<<"2 father:"<<father<<" son:"<<son<<endl;
            //子是新的，父已在 => 对子重新赋值
            markval[son] = markval[father] / val;
            fathermp[son] = find(fathermp, father);
        }
        else if (fathermp.find(father) == fathermp.end() && fathermp.find(son) != fathermp.end()) {
            // cout<<"3 father:"<<father<<" son:"<<son<<endl;
            //父是新的，子已在 => 调头同上
            markval[father] = val * markval[son];
            fathermp[father] = find(fathermp, son);
        }
        else {
            // cout<<"4 father:"<<father<<" son:"<<son<<endl;
            //父子在不同树；合并两颗树 对父所在的树 和 对子所在的树  都乘以val倍
            val *= markval[son] / markval[father];
            father = find(fathermp, father);
            son = find(fathermp, son);
            if (father == son)  //父子在一棵树
                return;
            for (auto key = fathermp.begin(); key != fathermp.end(); ++key) {
                if (find(fathermp, key->first) == father) {
                    markval[key->first] = markval[key->first] * val;
                }
            }
            fathermp[son] = father;
        }
    }

    vector<double>
    calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, string> fathermp;  //找到key的father是谁
        map<string, double> markval;   //找到key的father对应的val是多少
        for (int i = 0; i < equations.size(); ++i) {
            string father = equations[i][0];
            string son = equations[i][1];
            double val = values[i];
            merge(fathermp, markval, father, son, val);
        }
        show(fathermp);
        show(markval);
        vector<double> ret;
        for (int i = 0; i < queries.size(); ++i) {
            string a = queries[i][0];
            string b = queries[i][1];
            ret.push_back(findval(fathermp, markval, a, b));
        }
        return ret;
    }
};

class Solution2 {
  public:
    vector<double>
    calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ret;
        map<string, int> mp;
        int cnt = 0;
        for (auto equation : equations) {
            for (auto key : equation) {
                if (mp.find(key) == mp.end()) {
                    mp[key] = cnt++;
                }
            }
        }
        vector<vector<double>> val(cnt, vector<double>(cnt, -1));
        for (int i = 0; i < equations.size(); ++i) {
            val[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            val[mp[equations[i][1]]][mp[equations[i][0]]] = 1 / values[i];
        }
        for (int k = 0; k < cnt; ++k) {
            for (int i = 0; i < cnt; ++i) {
                for (int j = 0; j < cnt; ++j) {
                    if (val[i][j] == -1 && val[i][k] != -1 && val[k][j] != -1) {
                        val[i][j] = val[i][k] * val[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end())
                ret.push_back(-1);
            else
                ret.push_back(val[mp[queries[i][0]]][mp[queries[i][1]]]);
        }
        return ret;
    }
};

class Solution {
  public:
    vector<double>
    calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ret;
        map<string, int> mp;
        int cnt = 0;
        for (auto equation : equations) {
            for (auto key : equation) {
                if (mp.find(key) == mp.end()) {
                    mp[key] = cnt++;
                }
            }
        }
        vector<vector<double>> val(cnt, vector<double>(cnt, -1));
        for (int i = 0; i < equations.size(); ++i) {
            val[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            val[mp[equations[i][1]]][mp[equations[i][0]]] = 1 / values[i];
        }
        for (int k = 0; k < cnt; ++k) {
            for (int i = 0; i < cnt; ++i) {
                for (int j = 0; j < cnt; ++j) {
                    if (val[i][j] == -1 && val[i][k] != -1 && val[k][j] != -1) {
                        val[i][j] = val[i][k] * val[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end())
                ret.push_back(-1);
            else
                ret.push_back(val[mp[queries[i][0]]][mp[queries[i][1]]]);
        }
        return ret;
    }
};

int main() {
    Solution A;
    // vector<vector<string>> equations{{"a", "b"}, {"e", "f"}, {"b", "e"}};
    // vector<double> values{3.4, 1.4, 2.3};
    // vector<vector<string>> queries{{"b","a"}, {"a","f"}, {"f","f"}, {"e","e"}, {"c","c"}, {"a","c"}, {"f","e"}};
    // 0.294118 10.948      1      1     -1     -1 0.714286
    vector<vector<string>> equations{{"a", "b"}, {"e", "f"}, {"b", "e"}};
    vector<double> values{3.4, 1.4, 2.3};
    vector<vector<string>> queries{{"b", "a"}, {"a", "f"}, {"f", "f"}, {"e", "e"}, {"c", "c"}, {"a", "c"}, {"f", "e"}};
    show(A.calcEquation(equations, values, queries));

    // [["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]
    // [2.0,3.0,4.0,5.0,6.0,7.0,8.0]
    // [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","z"]]
    // [0.66667,0.33333,-1.0,1.0,1.0,0.04464]
    // vector<vector<string>> equations{{"a", "b"}, {"c", "b"}, {"d", "b"}, {"w", "x"}, {"y", "x"}, {"z", "x"}, {"w",
    // "d"}}; vector<double> values{2, 3, 4, 5, 6, 7, 8}; vector<vector<string>> queries{{"a","z"}, {"b","c"},
    // {"a","e"}, {"a","a"}, {"x","x"}, {"a","z"}};
    // show(A.calcEquation(equations, values, queries));

    return 0;
}
