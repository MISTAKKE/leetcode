#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList2(Node* head) {
        if(head == NULL)
            return NULL;
        map<Node*, int> dest_mp;
        Node* hebk = head;
        int nodecnt = 0;
        vector<Node>nodelist;
        for(int i = 0; hebk!=NULL;++i)
        {
            dest_mp[hebk] = i;
            nodecnt +=1;
            Node* newdata = new Node(hebk->val);
            nodelist.push_back(*newdata);
            hebk = hebk->next;
        }
        hebk = head;
        head = &(nodelist[0]);
        for(int i = 0; i<nodecnt; ++i)
        {
            if( i !=nodecnt-1 )
                nodelist[i].next = &(nodelist[i+1]); 
            if(hebk->random != NULL)
                nodelist[i].random = &(nodelist[dest_mp[hebk->random]]);
            hebk = hebk->next;
        }
        return head;
    }
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;
        Node* ptr=head;
        //复制节点
        while(head!=nullptr){
            Node* tmp=new Node(head->val);
            mp[head]=tmp;
            head=head->next;
        }
        //复制指针指向
        for(auto p:mp){
            p.second->next=mp[p.first->next];
            p.second->random=mp[p.first->random];
        }
        return mp[ptr];
    
    }
};

void show(Node* head)
{
    Node *head2 = head;
    Node *head3 = head;
    cout<<"show next: ";
    while(head!=NULL)
    {
        cout<<head->val<<"  ";
        head=head->next;
    }
    cout<<endl;

    cout<<"show random: ";
    while(head2!=NULL)
    {
        cout<<head2->random<<"  ";
        head2=head2->next;
    }
    cout<<endl;

    cout<<"show self: ";
    while(head3!=NULL)
    {
        cout<<head3<<"  ";
        head3=head3->next;
    }
    cout<<endl;
    cout<<endl;
}

int main()
{
    Solution A;

    Node* ret1 = new Node(0);
    Node* ret2 = new Node(1);
    Node* ret3 = new Node(3);
    ret1->next=ret2;
    ret2->next=ret3;
    ret1->random = ret2;
    ret2->random = ret3;
    ret3->random = ret1;
    show(ret1);
    Node *ret = A.copyRandomList(ret1);
    show(ret);
    return 0;
}
