#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:

请你实现 TextEditor 类：

TextEditor() 用空文本初始化对象。
void addText(string text) 将 text 添加到光标所在位置。添加完后光标在 text 的右边。
int deleteText(int k) 删除光标左边 k 个字符。返回实际删除的字符数目。
string cursorLeft(int k) 将光标向左移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
string cursorRight(int k) 将光标向右移动 k 次。返回移动后光标左边 min(10, len) 个字符，其中 len 是光标左边的字符数目。
 

示例 1：

输入：
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft",
"cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
输出：
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

解释：
TextEditor textEditor = new TextEditor(); // 当前 text 为 "|" 。（'|' 字符表示光标）
textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
textEditor.deleteText(4); // 返回 4
                          // 当前文本为 "leet|" 。
                          // 删除了 4 个字符。
textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
textEditor.cursorRight(3); // 返回 "etpractice"
                           // 当前文本为 "leetpractice|".
                           // 光标无法移动到文本以外，所以无法移动。
                           // "etpractice" 是光标左边的 10 个字符。
textEditor.cursorLeft(8); // 返回 "leet"
                          // 当前文本为 "leet|practice" 。
                          // "leet" 是光标左边的 min(10, 4) = 4 个字符。
textEditor.deleteText(10); // 返回 4
                           // 当前文本为 "|practice" 。
                           // 只有 4 个字符被删除了。
textEditor.cursorLeft(2); // 返回 ""
                          // 当前文本为 "|practice" 。
                          // 光标无法移动到文本以外，所以无法移动。
                          // "" 是光标左边的 min(10, 0) = 0 个字符。
textEditor.cursorRight(6); // 返回 "practi"
                           // 当前文本为 "practi|ce" 。
                           // "practi" 是光标左边的 min(10, 6) = 6 个字符。
*/

// Class Solution
//一个string
class TextEditor {
  public:
    std::string data;
    TextEditor() {
        data = "";
        idx = 0;
    }
    int idx{0};

    void addText(string text) {
        data.insert(idx, text);
        idx += text.size();
    }

    int deleteText(int k) {
        int cnt = 0;
        if (idx > k) {
            // "012" k=1 idx=3
            data.erase(idx - k, k);
            idx -= k;
            cnt = k;
        }
        else {
            data.erase(0, idx);
            cnt = idx;
            idx = 0;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        if (idx > k) {
            idx -= k;
        }
        else {
            idx = 0;
        }
        int len = min(10, idx);
        return data.substr(idx - len, len);
    }

    string cursorRight(int k) {
        if (data.size() - idx > k) {
            idx += k;
        }
        else {
            idx = data.size();
        }
        int len = min(10, idx);
        return data.substr(idx - len, len);
    }
};

//双栈
class TextEditor2 {
  public:
    stack<char> st1;
    stack<char> st2;
    TextEditor2() {}

    void addText(string text) {
        for (auto c : text) {
            st1.push(c);
        }
    }

    int deleteText(int k) {
        int cnt = 0;
        while (k--) {
            if (!st1.empty()) {
                st1.pop();
                cnt += 1;
            }
        }
        return cnt;
    }

    string cursorLeft(int k) {
        while (k-- && !st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int cnt = 10;
        stack<char> t;
        while (cnt-- && !st1.empty()) {
            t.push(st1.top());
            st1.pop();
        }
        string ret = "";
        while (!t.empty()) {
            st1.push(t.top());
            ret += t.top();
            t.pop();
        }
        return ret;
    }

    string cursorRight(int k) {
        while (k-- && !st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        int cnt = 10;
        stack<char> t;
        while (cnt-- && !st1.empty()) {
            t.push(st1.top());
            st1.pop();
        }
        string ret = "";
        while (!t.empty()) {
            st1.push(t.top());
            ret += t.top();
            t.pop();
        }
        return ret;
    }
};

//双向链表
class TextEditor1 {
  public:
    class Node {
      public:
        Node* before{nullptr};
        Node* next{nullptr};
        char val{' '};
        Node(char ch) : val(ch){};
    };
    Node* now;
    TextEditor1() {
        now = new Node('|');
    }
    ~TextEditor1() {
        // delete
        Node* b = now->before;
        while (b != nullptr) {
            Node* t = b;
            b = b->before;
            delete t;
        }
        while (now != nullptr) {
            Node* t = now;
            now = now->next;
            delete t;
        }
    }

    void addText(string text) {
        for (auto c : text) {
            Node* t = new Node(c);
            if (now->before != nullptr) {
                now->before->next = t;
                t->before = now->before;
                now->before = t;
                t->next = now;
            }
            else {
                t->next = now;
                now->before = t;
            }
        }
    }

    int deleteText(int k) {
        int ret = 0;
        while (k--) {
            if (now->before != nullptr) {
                // delete now->before
                Node* t = now->before;
                now->before = t->before;
                if (t->before != nullptr) {
                    t->before->next = now;
                }
                delete t;
                ++ret;
            }
            else {
                break;
            }
        }

        return ret;
    }

    string cursorLeft(int k) {
        while (k--) {
            if (now->before != nullptr) {
                // ... 34 t 56 now 12 ....
                Node* t = now->before;
                t->next = now->next;
                if (now->next != nullptr) {
                    now->next->before = t;
                }
                now->before = t->before;
                if (t->before != nullptr) {
                    t->before->next = now;
                }
                now->next = t;
                t->before = now;
            }
            else {
                break;
            }
        }
        string ret = "";
        Node* r = now;
        int cnt = 10;
        while (r->before != nullptr && cnt--) {
            ret += r->before->val;
            r = r->before;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string cursorRight(int k) {
        while (k--) {
            if (now->next != nullptr) {
                //  ... 12 now 56 t 34...
                Node* t = now->next;
                t->before = now->before;
                if (now->before != nullptr) {
                    now->before->next = t;
                }
                now->next = t->next;
                if (t->next != nullptr) {
                    t->next->before = now;
                }
                t->next = now;
                now->before = t;
            }
            else {
                break;
            }
        }
        string ret = "";
        Node* r = now;
        int cnt = 10;
        while (r->before != nullptr && cnt--) {
            ret += r->before->val;
            r = r->before;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void show() {
        Node* t = now;
        while (t->before != nullptr) {
            t = t->before;
        }
        string ret = "";
        while (t != nullptr) {
            ret += t->val;
            t = t->next;
        }
        cout << "showing: " << ret << endl;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {
    TextEditor textEditor;                      // 当前 text 为 "|" 。（'|' 字符表示光标）
    textEditor.addText("leetcode");             // 当前文本为 "leetcode|" 。
    cout << textEditor.deleteText(4) << endl;   // 返回 4
                                                // 当前文本为 "leet|" 。
                                                // 删除了 4 个字符。
    textEditor.addText("practice");             // 当前文本为 "leetpractice|" 。
    cout << textEditor.cursorRight(3) << endl;  // 返回 "etpractice"
                                                // 当前文本为 "leetpractice|".
                                                // 光标无法移动到文本以外，所以无法移动。
                                                // "etpractice" 是光标左边的 10 个字符。
    cout << textEditor.cursorLeft(8) << endl;   // 返回 "leet"
                                                // 当前文本为 "leet|practice" 。
                                                // "leet" 是光标左边的 min(10, 4) = 4 个字符。
    cout << textEditor.deleteText(10) << endl;  // 返回 4
                                                // 当前文本为 "|practice" 。
                                                // 只有 4 个字符被删除了。

    cout << textEditor.cursorLeft(2) << endl;   // 返回 ""
                                                // 当前文本为 "|practice" 。
                                                // 光标无法移动到文本以外，所以无法移动。
                                                // "" 是光标左边的 min(10, 0) = 0 个字符。
    cout << textEditor.cursorRight(6) << endl;  // 返回 "practi"
                                                // 当前文本为 "practi|ce" 。
                                                // "practi" 是光标左边的 min(10, 6) = 6 个字符。
    return 0;
}
