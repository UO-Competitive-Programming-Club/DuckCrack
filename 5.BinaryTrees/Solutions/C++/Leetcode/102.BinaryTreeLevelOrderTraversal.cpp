#include "../Debug.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    vector<TreeNode*> cur_level_iters;
    if (!root) {
        return result;
    }
    
    result.emplace_back(vector<int>{ root->val });
    cur_level_iters.emplace_back(root);

    while (!cur_level_iters.empty()) {
        vector<int> next_level_result;

        vector<TreeNode*> next_level_iters;
        for (size_t i = 0; i < cur_level_iters.size(); i++) {
            TreeNode* iter = cur_level_iters[i];
            if (iter->left) {
                next_level_iters.emplace_back(iter->left);
                next_level_result.emplace_back(iter->left->val);
            }

            if (iter->right) {
                next_level_iters.emplace_back(iter->right);
                next_level_result.emplace_back(iter->right->val);
            }
        }
        
        if (!next_level_result.empty()) {
            result.emplace_back(next_level_result);
        }
        cur_level_iters = next_level_iters;
    }

    return result;
}

