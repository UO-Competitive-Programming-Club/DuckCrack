#include "../Debug.h"
using namespace std;

bool isValidBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode);

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, NULL, NULL);
}

bool isValidBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) { 
        return true;
    }

    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        return false;
    }

    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
}

