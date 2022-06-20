#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class BrowserHistory {
  public:
    class DNode {
      public:
        DNode* before{nullptr};
        DNode* next{nullptr};
        std::string val{""};
        DNode(std::string v) : val(v){};
    };
    ~BrowserHistory() {
        freebefore();
    }
    DNode* now{nullptr};
    void freebefore(DNode* node) {
        while (node != nullptr) {
            DNode* t = node->before;
            delete node;
            node = t;
        }
    }
    void freeafter(DNode* node) {
        while (node != nullptr) {
            DNode* t = node->next;
            delete node;
            node = t;
        }
    }
    BrowserHistory(string homepage) {
        freebefore();
        now = new DNode(homepage);
    }

    void visit(string url) {
        DNode* newpage = new DNode(url);
        newpage->before = now;
        freeafter(now->next);
        now->next = newpage;
        now = newpage;
    }

    string back(int steps) {
        while (steps-- && now->before != nullptr) {
            now = now->before;
        }
        return now->val;
    }

    string forward(int steps) {
        while (steps-- && now->next != nullptr) {
            now = now->next;
        }
        return now->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
    Solution A;

    return 0;
}
