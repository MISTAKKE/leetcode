#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *p = new ListNode(0);
        ListNode *last = p;
        while (1)
        {
            int idx = -1;
            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] != NULL && (idx == -1 || lists[idx]->val > lists[i]->val))
                {
                    idx = i;
                }
            }
            if (idx != -1)
            {
                last->next = lists[idx];
                lists[idx] = lists[idx]->next;
                last = last->next;
                continue;
            }
            break;
        }
        ListNode *head = p->next;
        delete p;
        return head;
    }
};

class Solution2
{
public:
    class Node
    {
    public:
        ListNode *data;
        int idx;
        Node(ListNode *p, int i)
        {
            data = p;
            idx = i;
        }
        bool operator<(const Node &b) const
        {
            return data->val > b.data->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<Node, vector<Node>, less<Node>> q;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
            {
                ListNode *tmp = lists[i];
                lists[i] = lists[i]->next;
                tmp->next = NULL;
                q.push(Node(tmp, i));
            }
        }
        ListNode *p = new ListNode(0);
        ListNode *last = p;
        while (q.size() > 0)
        {
            Node node = q.top();
            last->next = node.data;
            last = last->next;
            q.pop();
            if (lists[node.idx] != NULL)
            {
                ListNode *tmp = lists[node.idx];
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
class Solution_bad
{
    struct Node
    {
        ListNode *p;
        Node(ListNode *data)
        {
            p = data;
        }
        bool operator<(const Node &node) const
        {
            return p->val > node.p->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<Node> vec;
        {
            for (int i = 0; i < lists.size(); ++i)
            {
                while (lists[i] != NULL)
                {
                    vec.push(Node(lists[i]));
                    lists[i] = lists[i]->next;
                }
            }
        }
        ListNode *p = new ListNode(0);
        ListNode *last = p;
        while(!vec.empty())
        {
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


class Solution
{
public:
    class Node
    {
    public:
        ListNode *data;
        Node(ListNode *p)
        {
            data = p;
        }
        bool operator<(const Node &b) const
        {
            return data->val > b.data->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<Node> q;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
            {
                ListNode *tmp = lists[i];
                q.push(Node(tmp));
            }
        }
        ListNode *p = new ListNode(0);
        ListNode *last = p;
        while (q.size() > 0)
        {
            Node node = q.top();
            last->next = node.data;
            last = last->next;
            q.pop();
            if (node.data->next != NULL)
            {
                q.push(Node(node.data->next));
            }
        }
        last = p->next;
        delete p;
        return last;
    }
};




int main()
{
    Solution A;
    ListNode *p = new ListNode(0);
    ListNode *p1 = new ListNode(10);
    ListNode *p11 = new ListNode(20);
    ListNode *p2 = new ListNode(6);
    ListNode *p21 = new ListNode(7);
    ListNode *p22 = new ListNode(17);
    p->next = p1;
    p1->next = p11;
    p2->next = p21;
    p21->next = p22;
    vector<ListNode *> vec{p, p2};
    show(A.mergeKLists(vec));
    return 0;
}
