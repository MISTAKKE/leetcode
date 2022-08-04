#include "../tool/helper.cpp"
using namespace std;

/*
description:

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次

*/

// Class Solution
class Trie {
  public:
    vector<Trie*> vec;
    bool end;
    /** Initialize your data structure here. */
    Trie() {
        vec.resize(26, NULL);
        end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto& c : word) {
            if (node->vec[c - 'a'] == NULL) {
                node->vec[c - 'a'] = new Trie();
            }
            node = node->vec[c - 'a'];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto& c : word) {
            if (node->vec[c - 'a'] == NULL) {
                return false;
            }
            node = node->vec[c - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto& c : prefix) {
            if (node->vec[c - 'a'] == NULL) {
                return false;
            }
            node = node->vec[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("word");
    obj->insert("world");
    obj->insert("worlds");
    obj->insert("worldss");
    obj->insert("worad");
    obj->insert("worbd");
    cout << obj->search("worldss") << endl;
    cout << obj->startsWith("worldss") << endl;
    return 0;
}
