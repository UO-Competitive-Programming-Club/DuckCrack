#include "../Debug.h"
using namespace std;

int height(TreeNode* root) { 
    if (root == nullptr) {
        return 0;
    }
    
    int left = height(root->left) + 1,
        right = height(root->right) + 1;

    return max(left, right);
}

bool isBalanced(TreeNode* root) { 
    if (root == nullptr) {
        return true;
    }

    int left_height = height(root->left),
        right_height = height(root->right);

    return (abs(left_height - right_height)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

