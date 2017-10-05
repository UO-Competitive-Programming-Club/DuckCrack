#include "../Debug.h"
using namespace std;

/* bruteforce */
int Rob(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int val = 0;
    if (root->left) {
        val += Rob(root->left->left) + Rob(root->left->right);
    }

    if (root->right) {
        val += Rob(root->right->left) + Rob(root->right->right);
    }
        
    return max(val + root->val, Rob(root->left) + Rob(root->right));
}

/* greedy solution */

struct RobStatus {
    int leave_max;
    int rob_max;
};

RobStatus RobSmartHelper(TreeNode* root) {
    if (!root) {
        return RobStatus{ 0, 0 };
    }

    RobStatus leftRS = RobSmartHelper(root->left),
              rightRS = RobSmartHelper(root->right),
              result;

    result.leave_max = max(leftRS.leave_max, leftRS.rob_max) + max(rightRS.leave_max, rightRS.rob_max);
    result.rob_max = root->val + leftRS.leave_max + rightRS.leave_max;
    return result;
}

int RobSmart(TreeNode* root) {
    RobStatus rootRS = RobSmartHelper(root);
    return max(rootRS.rob_max, rootRS.leave_max);
}
