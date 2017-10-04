#include "../Debug.h"
using namespace std;

vector<int> InorderTraversalIterative(TreeNode* root) {
    stack<TreeNode*> inorder_stack;
    vector<int> ret;
    TreeNode* iter = inorder_stack.top();
    while (!inorder_stack.empty() || iter) {
        if (iter) {
            inorder_stack.emplace(iter);
            iter = iter->left;
        } else {
            iter = inorder_stack.top();
            inorder_stack.pop();
            ret.emplace_back(iter->val);
            iter = iter->right;
        }
    }

    return ret;
}
