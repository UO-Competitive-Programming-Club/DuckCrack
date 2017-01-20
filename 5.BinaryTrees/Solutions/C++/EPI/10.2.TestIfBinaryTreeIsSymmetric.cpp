#include "../Debug.h"
using namespace std;

bool IsSymmetricHelper(TreeNode* left_mirror, TreeNode* right_mirror) {
    if (left_mirror == nullptr) {
        return (right_mirror == nullptr) ? true : false;
    } 

    if (right_mirror == nullptr) {
        return (left_mirror == nullptr) ? true : false;
    } 

    bool match = (left_mirror->val == right_mirror->val) && 
                 IsSymmetricHelper(left_mirror->left, right_mirror->right) && 
                 IsSymmetricHelper(left_mirror->right, right_mirror->left);
         
    return match;
}

bool IsSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    return IsSymmetricHelper(root->left, root->right);
}

