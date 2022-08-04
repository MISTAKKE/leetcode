#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

class Solution2  // no recursion
{
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            int cnt = q.size();
            res.push_back(vector<int>());
            while (cnt-- > 0) {
                TreeNode* t = q.front();
                q.pop();
                res.back().push_back(t->val);
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// Class Solution
class Solution1 {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left = 0, int right = __INT_MAX__, bool isleft = false) {
        if (nums.size() == 0 || left > right)
            return NULL;
        if (right == __INT_MAX__)
            right = nums.size() - 1;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (right - left == 1 && isleft) {
            TreeNode* newroot = new TreeNode(nums[right]);
            newroot->left = root;
            return newroot;
        }
        else {
            root->left = sortedArrayToBST(nums, left, mid - 1, true);
            root->right = sortedArrayToBST(nums, mid + 1, right, false);
        }
        // cout<<"left:"<<left<<" mid:"<<mid<<" right:"<<right<<endl;

        return root;
    }
};
class Solution {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return helper(nums, 0, nums.size() - 1, false);
    }
    TreeNode* helper(vector<int>& nums, int left, int right, bool isleft) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        cout << "left:" << left << " mid:" << mid << " right:" << right << endl;
        if (right - left == 1 && isleft) {
            TreeNode* newroot = new TreeNode(nums[right]);
            newroot->left = root;
            return newroot;
        }
        else {
            root->left = helper(nums, left, mid - 1, true);
            root->right = helper(nums, mid + 1, right, false);
        }
        return root;
    }
};
int main() {
    Solution A;
    Solution2 B;
    vector<int> res{1, 2, 3};
    show(res);
    TreeNode* root = A.sortedArrayToBST(res);
    show(B.levelOrderBottom(root));
    return 0;
}
