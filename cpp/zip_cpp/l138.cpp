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
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        map<uint64_t, int> dest_mp;
        vector<int>val;
        vector<int>random;
        Node* headbk = head;
        for(int i = 0; head!=NULL;++i)
        {
            dest_mp[(char*)head] = i;
            val.push_back(head->val);
            if(head->random == NULL)
                random.push_back(0);
            else
                random.push_back(&(head->random));
            head = head->next;
        }
        vector<Node>node;
        for(int i = 0; i<val.size(); ++i)
        {
            node.push_back(new Node(val[i]));
        }
        for(int i = 0; i<val.size(); ++i)
        {
            if( i !=val.size()-1 )
                node[i].next = node[i+1]; 
            dest_mp[(char*)head] = i;
            node[i].random = node[dest_mp[head->random]];
        }
        Node* ret = new Node(val[0]);
        return ret;
    }
};



int main()
{
    Solution A;

    return 0;
}
