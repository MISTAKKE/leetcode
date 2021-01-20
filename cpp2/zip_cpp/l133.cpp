#include "../tool/helper.cpp"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<int,Node*>visited;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;

        Node *p = new Node(node->val);
        visited[p->val] = p;

        for(int i = 0;i<node->neighbors.size(); ++i)
        {
            Node* tmp = node->neighbors[i];
            map<int, Node*>::iterator it = visited.find(tmp->val);
            if(it==visited.end())//没找到
            {
                Node *pnew = cloneGraph(tmp); 
                p->neighbors.push_back(pnew);
                visited[tmp->val] = pnew;
            }
            else//找到了
            {
                p->neighbors.push_back(visited[tmp->val]);
            }
        }

        return p; 
    }
};

int main()
{
    Solution A;

    return 0;
}
