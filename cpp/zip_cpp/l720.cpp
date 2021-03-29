#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        return "";
        Trie t;
    }
    class Node
    {
    public:
        char c;
        bool end;
        map<char, Node> mp;
        Node(char _c = ' ')
        {
            c = _c;
            end = false;
        }
    };
    class Trie
    {
    public:
        Node root;
        void insert(string &res)
        {
            Node &node = root;
            for (auto &c : res)
            {
                if (node.mp.find(c) != node.mp.end())
                {
                    root = node.mp[c];
                }
            }
        }
        bool exist(string &res)
        {
            return false;
        }
    };
};

int main()
{
    Solution A;

    return 0;
}
