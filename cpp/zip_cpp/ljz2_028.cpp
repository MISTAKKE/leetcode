#include "/root/leetcode/tool/helper.cpp"
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
  public:
    Node* last;
    Node* flatten(Node* head) {
        last = head;
        dfs(head->child);
        dfs(head->next);
        return head;
    }
    void dfs(Node* head) {
        if (head == NULL)
            return head;
        dfs(head->child);
        last->next = head;
        head->prev = last;
        head->child = NULL;
        last = head;
        dfs(head->next);
    }
};

int main() {
    Solution A;

    return 0;
}
