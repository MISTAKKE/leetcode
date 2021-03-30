#include "../tool/helper.cpp"
using namespace std;

/*
description:


solution0
1 字符串排序后，从小到大尝试insert进set中
2 用set存放所有ok的字符串，返回set中最长最小的string

Solution1
前缀树模板 + 每次search
复杂度分析
    insert 时间复杂度 sum(len(word)) = O(n*m)
    insert 空间复杂度 sum(len(word)) = O(n*m)
    search 时间复杂度 sum(len(word)) = O(n*m)
    search 空间复杂度 0
缺点：
    1 树用的是map而不是vector 24；
        map -> vector<int>(24, 0)
比较：
    dfs遍历前缀树和逐个search哪个效率高？
    结论：一样高


*/
class Solution1
{
public:
    string longestWord(vector<string> &words)
    {
        string ret = "";
        Trie t;
        for (auto &word : words)
        {
            t.insert(word);
        }
        for (auto &word : words)
        {
            if (t.exist(word))
            {
                if (word.size() > ret.size() || (word.size() == ret.size() && word < ret))
                    ret = word;
            }
        }
        return ret;
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
            Node *node = &root;
            for (auto &c : res)
            {
                if (node->mp.find(c) == node->mp.end())
                {
                    node->mp[c] = Node(c);
                }
                node = &(node->mp[c]);
            }
            node->end = true;
        }
        bool exist(string &res)
        {
            Node *node = &root;
            for (auto &c : res)
            {
                if (node->mp.find(c) == node->mp.end() || !node->mp[c].end)
                {
                    return false;
                }
                node = &(node->mp[c]);
            }
            return node->end;
        }
    };
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie t;
        string ret = "";
        for (auto &word : words)
        {
            t.insert(word);
        }
        for (auto &word : words)
        {
            if (t.exist(word))
            {
                if (word.size() > ret.size() || (word.size() == ret.size() && word < ret))
                    ret = word;
            }
        }
        return ret;
    }

    class Trie
    {
    public:
        bool end;
        vector<Trie *> vec;
        Trie()
        {
            vec.resize(26, NULL);
            end = false;
        }
        void insert(string &res)
        {
            Trie *tree = this;
            for (auto &c : res)
            {
                if (tree->vec[c - 'a'] == NULL)
                {
                    tree->vec[c - 'a'] = new Trie();
                }
                tree = tree->vec[c - 'a'];
            }
            tree->end = true;
        }
        bool exist(string &res)
        {
            Trie *tree = this;
            for (auto &c : res)
            {
                if (tree->vec[c - 'a'] == NULL || !(tree->vec[c - 'a']->end))
                {
                    return false;
                }
                tree = tree->vec[c - 'a'];
            }
            return true;
        }
    };
};
int main()
{
    Solution A;
    vector<string> vec{"a", "bc", "bcd", "bcde", "ab", "abc", "abcd", "b"};
    // vector<string> vec{"a", "ab"};
    cout << A.longestWord(vec) << endl;

    return 0;
}
