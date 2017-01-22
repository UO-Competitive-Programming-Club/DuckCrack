#include "../Debug.h"
using namespace std;

 /* this is a very fast iterative solution essentially those helper functions can be
  * iterative too, therefore the space complexity is O(1) */

bool Isleaf(TreeNode * root);
int RightMostNumber(TreeNode * root, int pre_val);
int LeftMostNumber(TreeNode * root, int pre_val);
int MiddleNumber(TreeNode * root, int pre_val);

bool Isleaf(TreeNode * root) {
    if (!root) { return 0; }
    return (root->left == nullptr && root->right == nullptr);
}
    
int LeftMostNumber(TreeNode * root, int pre_val) {
    if (!root) { return 0; }
    if (Isleaf(root)) { return pre_val; }
    int cur_val = (pre_val << 1);
    return LeftMostNumber(root->left, cur_val);
}

int RightMostNumber(TreeNode * root, int pre_val) {
    if (!root) { return 0; }
    if (Isleaf(root)) { return pre_val; }        
    int cur_val = (pre_val << 1) + 1;
    return RightMostNumber(root->right, cur_val);
}

int LeftMiddleNumber(TreeNode * root, int pre_val) {
    return RightMostNumber(root->left, pre_val << 1);
}

int RightMiddleNumber(TreeNode * root, int pre_val) {
    return LeftMostNumber(root->right, (pre_val << 1) + 1);
}

int countNodes(TreeNode* root) {
    if (!root) { return 0; }

    int leftmost, rightmost, leftmiddle, rightmiddle, cur_count = 1;
    TreeNode* next = root;

    do {
        leftmost     = LeftMostNumber(next, cur_count);
        rightmost    = RightMostNumber(next, cur_count);
        leftmiddle   = LeftMiddleNumber(next, cur_count);
        rightmiddle  = RightMiddleNumber(next, cur_count);

        /* this means the last node is at the left subtree */
        if (leftmiddle < rightmost) {
            next = next->left;
            cur_count = cur_count << 1;
        } else {
            if (leftmiddle > rightmiddle) {
                next = next->left;
                cur_count = cur_count << 1;
            } else {
                next = next->right;
                cur_count = (cur_count << 1) + 1;
            }
        }
    } while (leftmost != leftmiddle && leftmost > rightmost);

    return max(leftmost, rightmost);
}
