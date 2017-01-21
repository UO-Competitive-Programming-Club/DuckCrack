#include "../Debug.h"
using namespace std;

int sumNumbersHelper(TreeNode* root, int parent_number);

int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
}

int sumNumbersHelper(TreeNode* root, int parent_number) {
    if (!root) { return 0; }
    
    int self_number = parent_number * 10 + root->val;
    
    if (!root->left && !root->right) { return self_number; }
    
    int leftsubtree_sum = sumNumbersHelper(root->left, self_number),
        rightsubtree_sum = sumNumbersHelper(root->right, self_number);
        
    return leftsubtree_sum + rightsubtree_sum;
}
