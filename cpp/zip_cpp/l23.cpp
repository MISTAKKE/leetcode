#include "../tool/helper.cpp"
using namespace std;

/*
description:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
*/

// 22.30

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                q.push((10001 + lists[i]->val) * 10001 + i);
            }
        }
        while (!q.empty()) {
            int idx = q.top() % 10001;
            q.pop();
            tail->next = lists[idx];
            tail = tail->next;
            lists[idx] = lists[idx]->next;
            if (lists[idx] != nullptr) {
                q.push((10001 + lists[idx]->val) * 10001 + idx);
            }
        }

        tail = head->next;
        delete head;
        return tail;
    }
};

class Cmp {
  public:
    bool operator()(const pair<int, ListNode*> a, const pair<int, ListNode*> b) {
        return a.second->val > b.second->val;
    }
};
class Solution_99 {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Cmp> q;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                q.push(make_pair(i, lists[i]));
            }
        }
        while (!q.empty()) {
            ListNode* p = q.top().second;
            int idx = q.top().first;
            q.pop();
            tail->next = p;
            tail = p;
            cout << "p->val:" << p->val << endl;
            if (lists[idx]->next != nullptr) {
                lists[idx] = lists[idx]->next;
                q.push(make_pair(idx, lists[idx]));
            }
        }
        ListNode* tmp = head->next;
        delete head;
        return tmp;
    }
};

class Solution1 {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p = new ListNode(0);
        ListNode* last = p;
        while (1) {
            int idx = -1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != NULL && (idx == -1 || lists[idx]->val > lists[i]->val)) {
                    idx = i;
                }
            }
            if (idx != -1) {
                last->next = lists[idx];
                lists[idx] = lists[idx]->next;
                last = last->next;
                continue;
            }
            break;
        }
        ListNode* head = p->next;
        delete p;
        return head;
    }
};

class Solution2 {
  public:
    class Node {
      public:
        ListNode* data;
        int idx;
        Node(ListNode* p, int i) {
            data = p;
            idx = i;
        }
        bool operator<(const Node& b) const {
            return data->val > b.data->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node, vector<Node>, less<Node>> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                ListNode* tmp = lists[i];
                lists[i] = lists[i]->next;
                tmp->next = NULL;
                q.push(Node(tmp, i));
            }
        }
        ListNode* p = new ListNode(0);
        ListNode* last = p;
        while (q.size() > 0) {
            Node node = q.top();
            last->next = node.data;
            last = last->next;
            q.pop();
            if (lists[node.idx] != NULL) {
                ListNode* tmp = lists[node.idx];
                lists[node.idx] = lists[node.idx]->next;
                tmp->next = NULL;
                q.push(Node(tmp, node.idx));
            }
        }
        last = p->next;
        delete p;
        return last;
    }
};

/*
    一次把所有节点load到内存中，不是很好
    不能过在线测试，不知为何
*/
class Solution_bad {
    struct Node
    {
        ListNode* p;
        Node(ListNode* data) {
            p = data;
        }
        bool operator<(const Node& node) const {
            return p->val > node.p->val;
        }
    };

  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> vec;
        {
            for (int i = 0; i < lists.size(); ++i) {
                while (lists[i] != NULL) {
                    vec.push(Node(lists[i]));
                    lists[i] = lists[i]->next;
                }
            }
        }
        ListNode* p = new ListNode(0);
        ListNode* last = p;
        while (!vec.empty()) {
            Node node = vec.top();
            vec.pop();
            last->next = node.p;
            last = last->next;
        }
        last = p->next;
        delete p;
        return last;
    }
};

class Solution3 {
  public:
    class Node {
      public:
        ListNode* data;
        Node(ListNode* p) {
            data = p;
        }
        bool operator<(const Node& b) const {
            return data->val > b.data->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                ListNode* tmp = lists[i];
                q.push(Node(tmp));
            }
        }
        ListNode* p = new ListNode(0);
        ListNode* last = p;
        while (q.size() > 0) {
            Node node = q.top();
            last->next = node.data;
            last = last->next;
            q.pop();
            if (node.data->next != NULL) {
                q.push(Node(node.data->next));
            }
        }
        last = p->next;
        delete p;
        return last;
    }
};

int main() {
    Solution A;
    ListNode* p = new ListNode(0);
    ListNode* p1 = new ListNode(10);
    ListNode* p11 = new ListNode(20);
    ListNode* p2 = new ListNode(6);
    ListNode* p21 = new ListNode(7);
    ListNode* p22 = new ListNode(17);
    p->next = p1;
    p1->next = p11;
    p2->next = p21;
    p21->next = p22;
    vector<ListNode*> vec{p, p2};
    show(A.mergeKLists(vec));
    return 0;
}
