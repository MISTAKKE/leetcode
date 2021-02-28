#include "stdio.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print()
{
    cout <<endl;
} // 递归终止条件。这是必需的。
 
template<typename Type, typename... Types>
void print(const Type& arg, const Types&... args)
{
    std::cout << arg << " ";
    print(args...);
}

template<typename T1, typename T2>void show(const map<T1, T2> mp)
{
    for(auto c:mp)
    {
        cout << setw(6) << c.first << ":" << c.second <<endl;
    }
    cout << endl;
}

template<typename T>void show(const stack<T> st2)
{
    stack<T> st = st2;
    vector<T> vec;
    while(!st.empty())
    {
        vec.push_back(st.top());
        st.pop();
    }
    for(auto c:vec)
    {
        cout << setw(6) << c <<endl;
    }
    cout << endl;
}

template<typename T>void show(const vector<T> vec2)
{
    for(int i=0; i<vec2.size(); ++i)
        cout << setw(6) << vec2[i]<< " ";
    cout <<endl;
}

template<typename T>void show(const vector<vector<T>> vec2)
{
    for(int i=0; i<vec2.size(); ++i)
        show(vec2[i]);
    cout <<endl;
}

template<typename T>void show(const queue<T> q)
{
    queue<T> q2 = q;
    while(!q2.empty())
    {
        cout << setw(6) << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
}


template<typename T>void show(const set<T> q)
{
    set<T> q2 = q;
    for(auto iter = q.begin();iter!=q.end(); ++iter)
    {
        cout << setw(6) << *iter << " ";
    }
    cout << endl;
}

template<class T1, class T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &_)
{
    return out << "(" << _.first << ", " << _.second << ")";
}

void test()
{
    vector<int> vec {1,2,3,4,7,6,5};
    vector<vector<int>> vec2(3, vec);
    show(vec2);

    queue<string> qs;
    qs.push("abc");
    qs.push("def");

    stack<float> st;
    st.push(1.0);
    st.push(1.301);
    st.push(1.011);

    show(vec);
    show(qs);
    show(st);
}

int main_test()
{
    test();
    return 0;
}

