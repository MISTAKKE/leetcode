#include "../tool/helper.cpp"
using namespace std;

class Solution {
public:
    class Node{
    public:
        int x;
        int y;
        int val;
        Node(int x1, int y1, int val1):x(x1),y(y1),val(val1){};
        bool operator<(const Node& b) const 
        {
            return val > b.val; //小顶堆
        };
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, less<Node> > c;
        int inf = 0x3f3f3f3f;
        int st = nums[0][0];
        int ed = nums[0][0];
        int minlen = inf;
        int maxval = nums[0][0];
        for(int i = 0; i<nums.size(); ++i)
        {
            c.push(Node(i, 0, nums[i][0]));
            maxval = max(maxval, nums[i][0]);   
        }
        while(true)
        {
            Node now = c.top();//minval
            c.pop();
            int x = now.x;
            int y = now.y;
            int val = now.val;
            
            if(maxval - val < minlen)
            {
                st = val;
                ed = maxval;
                minlen = maxval - val;
            }

            if(y == nums[x].size()-1)
            {
                break;
            }
            else
            {
                c.push(Node(x, y+1, nums[x][y+1]));
            }

            maxval = max(maxval, nums[x][y+1]);
        }
        return vector<int>{st, ed};
    };

};

int main()
{
    Solution A;
    vector<vector<int>> nums{
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };
    show(nums);
    show(A.smallestRange(nums));
    return 0;
}
