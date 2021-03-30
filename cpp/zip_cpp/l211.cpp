#include "../tool/helper.cpp"
using namespace std;

/*
description:

实现词典类 WordDictionary ：
WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 
输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 
提示：
1 <= word.length <= 500
addWord 中的 word 由小写英文字母组成
search 中的 word 由 '.' 或小写英文字母组成
最多调用 50000 次 addWord 和 search

*/

//Class Solution
class WordDictionary
{
public:
    vector<WordDictionary *> vec;
    bool end;
    /** Initialize your data structure here. */
    WordDictionary()
    {
        vec.resize(26, NULL);
        end = false;
    }

    void addWord(string word)
    {
        WordDictionary *node = this;
        for (auto &c : word)
        {
            if (node->vec[c - 'a'] == NULL)
            {
                node->vec[c - 'a'] = new WordDictionary();
            }
            node = node->vec[c - 'a'];
        }
        node->end = true;
    }

    bool search(string word)
    {
        searchdo(word, 0);
    }
    bool searchdo(string &word, int start)
    {
        WordDictionary *node = this;
        for (int i = start; i < word.size(); ++i)
        {
            char &c = word[i];
            if (c == '.')
            {
                for (int k = 0; k < 26; ++k)
                {
                    if (node->vec[k] != NULL)
                    {
                        if (i + 1 == word.size() || node->vec[k]->searchdo(word, i + 1))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (node->vec[c - 'a'] == NULL)
            {
                node->vec[c - 'a'] = new WordDictionary();
            }
            node = node->vec[c - 'a'];
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    WordDictionary* obj = new WordDictionary();
    obj->addWord("a");
    obj->addWord("a");
    cout<<obj->search("a.")<<endl;
    return 0;
}

// ["WordDictionary",  "addWord","addWord",      "search","search","search","search","search","search"]
// [[],                ["a"],["a"],                 ["."],["a"],["aa"],["a"],[".a"],["a."]]
// 输出：
// [null,null,null,                            true,true,false,true,false,true]
// 预期结果：
// [null,null,null,                            true,true,false,true,false,false]