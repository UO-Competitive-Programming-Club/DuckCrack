#include "../Debug.h"
using namespace std;

vector<int> TreeLeftSide(TreeNode* root) {
    vector<int> result;
    auto iter = root;
    while (iter) {
        while (iter->left) { result.emplace_back(iter->val); }
        iter = iter->right;
    }

    result.pop_back();
    return result;
}

vector<int> TreeRightSide(TreeNode* root) {
    vector<int> result;
    auto iter = root->right;
    while (iter) {
        while (iter->right) { result.emplace_back(iter->val); }
        iter = iter->left;
    }

    result.pop_back();
    return result;
}

void TreeLeavesHelper(TreeNode* root, vector<int>& A) {
    if (root) {
        if (!root->left && !root->right) {
            A.emplace_back(root->val);
        }

        TreeLeavesHelper(root->left, A);
        TreeLeavesHelper(root->right, A);
    }
}

vector<int> TreeLeaves(TreeNode* root) {
    vector<int> A;
    TreeLeavesHelper(root, A);
    return A;
}

vector<int> ExteriorTree(TreeNode* root) {
    vector<int> leftside = TreeRightSide(root),
                rightside = TreeLeftSide(root),
                leaves = TreeLeaves(root);

    leftside.insert(leftside.end(), leaves.begin(), leaves.end());
    leftside.insert(leftside.end(), rightside.begin(), rightside.end());

    return leftside;
}
