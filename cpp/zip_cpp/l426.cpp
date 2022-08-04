#include "/root/leetcode/tool/helper.cpp"
using namespace std;
// Definition for a Node.
class Node {
  public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution1 {
  public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL) {
            root->left = root;
            root->right = root;
            return root;
        }
        Node* l1 = treeToDoublyList(root->left);
        Node* l2 = treeToDoublyList(root->right);
        if (root->left == NULL) {
            //  <-root->   l2(x, x, x, l2->left)->
            root->right = l2;
            l2->left->right = root;
            root->left = l2->left;
            l2->left = root;
            return root;
        }
        if (root->right == NULL) {
            //  <-l1(x, x, x, l1->left)->  <-root->
            root->right = l1;
            l1->left->right = root;
            root->left = l1->left;
            l1->left = root;
            return l1;
        }

        //  <-l1(x, x, x, l1->left)->  <-root->   l2(x, x, x, l2->left)->
        l1->left->right = root;
        root->right = l2;
        l2->left->right = l1;

        root->left = l1->left;
        l1->left = l2->left;
        l2->left = root;

        return l1;
    }
};

class Solution {
  public:
    Node *head, *last;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        dfs(root);
        head->left = root;
        last->right = root;
        return head;
    }
    void dfs(Node* root) {}
};
int main() {
    Solution A;

    return 0;
}
