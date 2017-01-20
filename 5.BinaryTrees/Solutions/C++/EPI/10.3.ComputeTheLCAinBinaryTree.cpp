#include "../Debug.h"
using namespace std;

struct Status {
    TreeNode* ancestor;
    int target_num;
};


Status LowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q);

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return LowestCommonAncestorHelper(root, p, q).ancestor;
}


Status LowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return {root, 0};
    }

    auto left_status = LowestCommonAncestorHelper(root->left, p, q);
    if (left_status.target_num == 2) {
        return left_status;
    }

    auto right_status = LowestCommonAncestorHelper(root->right, p, q);
    if (right_status.target_num == 2) {
        return right_status;
    }

    int num_target = left_status.target_num + right_status.target_num + ((root == p || root == q) ? 1 : 0);
    
    return { (num_target == 2) ? root : nullptr, num_target };
}


