#include "../Debug.h"
using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

bool hasLeftChild(TreeLinkNode* root);
void ConnectHelper(TreeLinkNode* left_iter, TreeLinkNode* right_iter);
void connect(TreeLinkNode *root);

void connect(TreeLinkNode *root) {
    if (root) {
        ConnectHelper(root->left, root->right);
    }
}

bool hasLeftChild(TreeLinkNode* root) {
    return root->left;
}

void ConnectHelper(TreeLinkNode* left_iter, TreeLinkNode* right_iter) {
    if (left_iter && right_iter) {
        left_iter->next = right_iter;
        ConnectHelper(left_iter->left, left_iter->right);
        ConnectHelper(left_iter->right, right_iter->left);
        ConnectHelper(right_iter->left, right_iter->right);
    }
}

