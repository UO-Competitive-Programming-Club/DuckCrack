#include "../Debug.h"
using namespace std;

int SumTheRootHelper(TreeNode* root, int cur_val);

int SUmTheRoot(TreeNode* root) {
    return SumTheRootHelper(root, root->val);
}

int SumTheRootHelper(TreeNode* root, int cur_val) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return cur_val;
    }

    int left_sum = SumTheRootHelper(root->left, (cur_val << 1) + root->val),
        right_sum = SumTheRootHelper(root->right, (cur_val << 1) + root->val);

    return left_sum + right_sum;
}
