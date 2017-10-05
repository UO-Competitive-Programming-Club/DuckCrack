#include "../Debug.h"
using namespace std;

struct ParentedTreeNode {
    int val;
    ParentedTreeNode *left;
    ParentedTreeNode *right;
    ParentedTreeNode *parent;
    ParentedTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ParentedTreeNode* Successor(ParentedTreeNode* node) {
    auto* iter = node;
    if (iter->right) {
        iter = iter->right;
        while (iter && iter->left) {
            iter = iter->left;
        }
        return iter;
    }

    while (iter->parent && iter->parent->right == iter) {
        iter = iter->parent;
    }

    return iter->parent;
}
