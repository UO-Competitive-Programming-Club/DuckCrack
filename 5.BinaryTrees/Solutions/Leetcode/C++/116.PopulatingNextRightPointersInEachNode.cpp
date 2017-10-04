#include "../Debug.h"
using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

bool hasLeftChild(TreeLinkNode* root);
void ConnectHelper(TreeLinkNode* left_iter, TreeLinkNode* right_iter);
void ConnectRecursive(TreeLinkNode *root);

bool hasLeftChild(TreeLinkNode* root) {
    return (root->left != nullptr);
}

void ConnectRecursive(TreeLinkNode *root) {
    if (root) {
        ConnectHelper(root->left, root->right);
    }
}

void ConnectHelper(TreeLinkNode* left_iter, TreeLinkNode* right_iter) {
    if (left_iter && right_iter) {
        left_iter->next = right_iter;
        ConnectHelper(left_iter->left, left_iter->right);
        ConnectHelper(left_iter->right, right_iter->left);
        ConnectHelper(right_iter->left, right_iter->right);
    }
}

void ConnectIterative(TreeLinkNode* root) {
    auto level_start_iter = root;
    while (level_start_iter) {
        auto level_iter = level_start_iter;
        while (level_iter) {
            if (hasLeftChild(level_iter)) {
                level_iter->left->next = level_iter->right;
                if (level_iter->next) {
                    level_iter->right->next = level_iter->next->left;
                }
            }
            level_iter = level_iter->next;
        }
        level_start_iter = level_start_iter->left;
    }
}

