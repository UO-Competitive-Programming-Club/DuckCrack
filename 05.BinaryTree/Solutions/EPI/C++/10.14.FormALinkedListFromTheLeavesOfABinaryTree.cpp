#include "../Debug.h" 
using namespace std;

void LeavesLinkedListHelper(TreeNode* root, list<TreeNode*> result);

list<TreeNode*> LeavesLinkedList(TreeNode* root) {
    list<TreeNode*> result;
    LeavesLinkedListHelper(root, result);
    return result;
}

void LeavesLinkedListHelper(TreeNode* root, list<TreeNode*> result) {
    if (root) {
        if (!root->left && root->right) {
            result.emplace_back(root);
        }       

        LeavesLinkedListHelper(root->left, result);
        LeavesLinkedListHelper(root->right, result);
    }
}
