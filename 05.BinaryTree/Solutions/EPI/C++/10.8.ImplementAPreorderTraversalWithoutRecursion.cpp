#include "../Debug.h"
using namespace std;

vector<int> PreorderIterative(TreeNode* root) {
    stack<TreeNode*> preorder_stack;
    preorder_stack.emplace(root);
    vector<int> ret;
    while (!preorder_stack.empty()) {
        auto iter = preorder_stack.top();
        preorder_stack.pop();
        if (iter) {
            ret.emplace_back(iter->data);
            preorder_stack.emplace(iter->left);
            preorder_stack.emplace(iter->right);
        }
    }

    return result;
}
