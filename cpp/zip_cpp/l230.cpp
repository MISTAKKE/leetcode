#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) {
        int kthval = -1;
        count(root, k, kthval);
        return kthval;
    }
    int count(TreeNode* root, int k, int& kthval) {
        //找到结果，速度退出
        if (kthval != -1) {
            return 0;
        }
        //如果为空则长度为1
        if (root == nullptr) {
            return 0;
        }
        //左边搜寻
        int count_left = count(root->left, k, kthval);
        //找到结果，速度退出
        if (kthval != -1) {
            return 0;
        }
        //刚好碰到结果，速度退出
        if (k == count_left + 1) {
            kthval = root->val;
            return 0;
        }
        //右边搜寻
        int count_right = count(root->right, k - count_left - 1, kthval);
        //找到结果，速度退出
        if (kthval != -1) {
            return 0;
        }
        //返回root的节点数
        return 1 + count_left + count_right;
    }
};

int main() {
    Solution A;

    return 0;
}
