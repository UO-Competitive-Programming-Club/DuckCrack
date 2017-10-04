#include "../Debug.h"
using namespace std;

/* brutefoce solution requires a lot of space */
vector<int> rightSideViewBruteforceHelper(TreeNode* root, vector<int> cur_view);

vector<int> rightSideViewBruteforce(TreeNode* root) {
    return rightSideViewBruteforceHelper(root, { });
}

vector<int> rightSideViewBruteforceHelper(TreeNode* root, vector<int> cur_view) {
    if (!root) {
        return cur_view;
    }

    cur_view.emplace_back(root->val);
    vector<int> left_rightview = rightSideViewBruteforceHelper(root->left, cur_view),
                right_rightview = rightSideViewBruteforceHelper(root->right, cur_view);

    if (right_rightview.size() >= left_rightview.size()) {
        return right_rightview;
    }

    right_rightview.insert(right_rightview.end(), 
            left_rightview.begin() + right_rightview.size(), left_rightview.end());

    return right_rightview;
}

/* in place solution */
void rightSideViewHelper(TreeNode* root, vector<int>& result, int cur_depth) {
    if (root) {
        if (cur_depth == (int) result.size()) {
            result.emplace_back(root->val);
        }

        rightSideViewHelper(root->right, result, cur_depth + 1);
        rightSideViewHelper(root->left, result, cur_depth + 1);
    }
}


vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    rightSideViewHelper(root, result, 0);
    return result;
}
