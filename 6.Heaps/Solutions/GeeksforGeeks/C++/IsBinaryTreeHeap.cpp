#include "../Debug.h"
using namespace std;

int TreeSize(TreeNode * root) {
    if (!root) { return 0; }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

bool IsBinaryTreeHeapHelper(TreeNode* root, int tsize, int index) {
    if (!root) { return true; }
    if (index > tsize) { return false; }
    if ( (root->left && root->left->val > root->val) || 
         (root->right && root->right->val > root->val) ) {
        return false;
    }

    return IsBinaryTreeHeapHelper(root, tsize, index * 2) && 
           IsBinaryTreeHeapHelper(root, tsize, index * 2 + 1);
}

bool IsBinaryTreeHeap(TreeNode* root) {
    return IsBinaryTreeHeapHelper( root, TreeSize(root), 0 );
}

