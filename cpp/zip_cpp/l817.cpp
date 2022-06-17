#include "../tool/helper.cpp"
using namespace std;

/*
description:

如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000

*/

// Class Solution

class Solution {
  public:
    int numComponents(ListNode* head, vector<int>& nums) {
        vector<bool> exist(10000, false);
        for (auto c : nums) {
            exist[c] = true;
        }
        int res = 0;
        while (head != nullptr) {
            if (exist[head->val] && (head->next == nullptr || !exist[head->next->val])) {
                res += 1;
            }
            head = head->next;
        }
        return res;
    }
};

int main() {
    Solution A;

    ListNode* p = MakeListNode({0, 1, 2, 3});
    vector<int> vec{2, 3, 0};
    cout << A.numComponents(p, vec) << endl;
    return 0;
}
