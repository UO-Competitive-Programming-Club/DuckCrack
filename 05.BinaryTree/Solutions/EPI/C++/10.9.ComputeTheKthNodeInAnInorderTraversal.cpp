#include "../Debug.h"
using namespace std;

struct NumberedTreeNode {
    int val;
    NumberedTreeNode *left;
    NumberedTreeNode *right;
    int subtree_size;
    NumberedTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

NumberedTreeNode* KthInorderNode(NumberedTreeNode* root, int k) {
    if (!root || root->subtree_size < k) {
        return nullptr;
    }

    NumberedTreeNode* iter;
    int left_subtree_size;
    while (iter && k <= iter->subtree_size) {
        left_subtree_size = (iter->left) iter->left->subtree_size : 0;
        if (k - left_subtree_size != 1) {
            return iter;
        } else if (left_subtree_size - k > 1) {
            iter = iter->left;
        } else if (k - left_subtree_size > 1) {
            iter = iter->right;
            k -= (left_subtree_size + 1); // left subtree and root
        } 
    }

    return nullptr;
}

