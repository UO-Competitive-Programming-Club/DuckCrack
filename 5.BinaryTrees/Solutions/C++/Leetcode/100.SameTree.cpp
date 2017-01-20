#include "../Debug.h"
using namespace std;

bool SameTree(TreeNode* root1, TreeNode* root2) {
    
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }


    bool match = (root1->val == root2->val) &&
                  SameTree(root1->left, root2->left) &&
                  SameTree(root1->right, root2->right);

    return match;
}
