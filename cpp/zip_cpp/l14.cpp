#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
public:
    class Node {                                                                                                                                                                                              
      public:
        int x;
        int y;
        int val;
        Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_){};
        bool operator<(const Node& b) const {
            return val > b.val;
        }   
    };  
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[0]< b[0];
    }
    
    string demo(string s, vector<vector<int>>& pairs) {
        vector<vector<int>>res;
        std::sort(res.begin(), res.end(), comp);
        priority_queue<Node, vector<Node>, less<Node>> neighbor;
        return "";
    }
};

int main() {
    Solution A;

    return 0;
}
