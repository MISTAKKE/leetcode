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
    }
    class Node
    {
        char c;
        bool end;
        map<char, Node> mp;
    };
    class Trie
    {
    public:
        char c;
        
        Trie()
        {
            c = 0;
            end = false;
        }
        bool insert(string &res)
        {

        }
        bool exist(string &res)
        {

        }
    };
};

int main()
{
    Solution A;

    return 0;
}
