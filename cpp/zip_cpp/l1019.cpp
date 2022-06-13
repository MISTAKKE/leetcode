#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
class Solution {
  public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        int idx = 0, n = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++n;
            p = p->next;
        }
        vector<int> ret(n, 0);
        while (head != nullptr) {
            if (st.empty() || st.top().first >= head->val) {
                // cout << "push " << head->val << " " << idx << endl;
                st.push(make_pair(head->val, idx++));
            }
            else {
                while (!st.empty() && st.top().first < head->val) {
                    // cout << "pop " << head->val << " " << st.top().second << endl;
                    ret[st.top().second] = head->val;
                    st.pop();
                }
                // cout << "push " << head->val << " " << idx << endl;
                st.push(make_pair(head->val, idx++));
            }
            head = head->next;
        }
        return ret;
    }
};

int main() {
    Solution A;
    vector<int> res{2, 7, 4, 3, 5};
    ListNode* p = MakeListNode(res);
    show(A.nextLargerNodes(p));

    return 0;
}
