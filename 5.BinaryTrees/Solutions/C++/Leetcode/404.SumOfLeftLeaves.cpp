#include "../Debug.h"

int SumOfLeftLeavesHelper(TreeNode* root, bool isleftchild);

int sumOfLeftLeaves(TreeNode* root) {
    return SumOfLeftLeavesHelper(root, 0);
}

int SumOfLeftLeavesHelper(TreeNode* root, bool isleftchild) {
    if (root == nullptr) {
        return 0;
    }
    
    if (root->left == nullptr && root->right == nullptr) {
        return (isleftchild) ? root->val : 0;
    }

    int leftsubtree_sum = SumOfLeftLeavesHelper(root->left, 1),
        rightsubtree_sum = SumOfLeftLeavesHelper(root->right, 0);
    return leftsubtree_sum + rightsubtree_sum;
}
