#include "../Debug.h" 
using namespace std;

void LeavesLinkedListHelper(TreeNode* root, vector<TreeNode*> result);

vector<TreeNode*> LeavesLinkedList(TreeNode* root) {
    vector<TreeNode*> result;
    LeavesLinkedListHelper(root, result);
    return result;
}

void LeavesLinkedListHelper(TreeNode* root, vector<TreeNode*> result) {
    if (root) {
        if (!root->left && root->right) {
            result.emplace_back(root);
        }       

        LeavesLinkedListHelper(root->left, result);
        LeavesLinkedListHelper(root->right, result);
    }
}
