#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isTwoSymmetric(root->left, root->right);
    }
    bool isTwoSymmetric(TreeNode* l, TreeNode* r) {
        if(l==nullprt && r==nullprt){
            return true;
        }
        if(l==nullprt || r==nullprt){
            return false;
        }
        if(l->val != r->val){
            return false;
        }
        return isTwoSymmetric(l->left, r->right) && isTwoSymmetric(l->right, r->left);
    }
};

// Class Solution
class Solution1  // bsf + no recursion
{
  public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        vector<TreeNode*> vec;
        vector<int> idx;
        vec.push_back(root);
        while (vec.size() != 0) {
            // check is bio
            for (int i = 0; i < vec.size() / 2; ++i) {
                if (vec[i] == NULL && vec[vec.size() - 1 - i] != NULL) {
                    return false;
                }
                else if (vec[i] != NULL && vec[vec.size() - 1 - i] == NULL) {
                    return false;
                }
                else if (vec[i] == NULL && vec[vec.size() - 1 - i] == NULL) {
                    continue;
                }
                else if (vec[i]->val != vec[vec.size() - 1 - i]->val || idx[i] + idx[vec.size() - 1 - i] != 0) {
                    return false;
                }
            }

            idx.clear();
            vector<TreeNode*> vecnew;
            for (int i = 0; i < vec.size(); ++i) {
                if (vec[i] != NULL) {
                    vecnew.push_back(vec[i]->left);
                    vecnew.push_back(vec[i]->right);
                    if (vec.size() % 2 == 0 && i >= vec.size() / 2) {
                        idx.push_back(vec.size() / 2 - 1 - i);
                        idx.push_back(vec.size() / 2 - 1 - i);
                    }
                    else {
                        idx.push_back(vec.size() / 2 - i);
                        idx.push_back(vec.size() / 2 - i);
                    }
                }
            }
            vec = vecnew;
        }
        return true;
    }
};

// Class Solution
class Solution2  // recursion
{
  public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isSymmetricTwo(root->left, root->right);
    }
    bool isSymmetricTwo(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        else if (l == NULL && r != NULL) {
            return false;
        }
        else if (l != NULL && r == NULL) {
            return false;
        }
        else if (l->val != r->val) {
            return false;
        }
        return isSymmetricTwo(l->left, r->right) * isSymmetricTwo(l->right, r->left);
    }
};

int main() {
    Solution A;
    TreeNode l(2, NULL, NULL);
    TreeNode r(2, NULL, NULL);

    TreeNode l2(76, NULL, NULL);
    TreeNode r1(76, NULL, NULL);

    TreeNode l22(13, NULL, NULL);
    TreeNode r12(13, NULL, NULL);
    l.right = &l2;
    r.left = &r1;
    l2.right = &l22;
    r1.right = &r12;

    TreeNode p(1);
    p.left = &l;
    p.right = &r;
    cout << A.isSymmetric(&p) << endl;
    return 0;
}

//            [9,
//     -42,        -42,        l  r
//   null,76,     76,null,  l2    r1
//     null,13, null,13]   l22    r12