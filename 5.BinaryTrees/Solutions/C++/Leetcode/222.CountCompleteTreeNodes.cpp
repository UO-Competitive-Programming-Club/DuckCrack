#include "../Debug.h"
using namespace std;

/* this solution beat 99% */ 
/* since the tree is complete the height of the tree */
/* is the height of the left most node */
int HeightCompleteTree(TreeNode * root) {
    if (!root) { return 0; }
    return HeightCompleteTree(root->left) + 1;
}

int CountNodes(TreeNode* root) {
    if (!root) { return 0; }
    int cur_count = 1;
    TreeNode* next = root;
    /* just like binary search, during each iteration we get a reference of the */
    /* root of the subtree where the LAST NODE of the complete binary tree resides in */
    /* while we are doing that we also calculate the current node count as if that node is */
    /* the last node, the iteration terminates when the root of the subtree is the last node itself,
     * by that time we know the count of the nodes already */
    while (next->left || next->right) {

        /* this means the LAST NODE is at the left subtree */
        if (HeightCompleteTree(next->left) > HeightCompleteTree(next->right)) {
            next = next->left;
            /* update the current count */
            cur_count = cur_count << 1;
        } else {
            next = next->right;
            /* update the current count */
            cur_count = (cur_count << 1) + 1;
        }
    }

    /* while loop terminate when "next" is the LAST NODE */
    return cur_count;
}
