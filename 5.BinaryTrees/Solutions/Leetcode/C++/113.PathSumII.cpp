#include "../Debug.h"

using namespace std;

void PathSumIIHelper(TreeNode* root, vector<vector<int>>& paths, 
        vector<int> cur_path, int prev_sum, int target) {

    if (root != nullptr) {
        int cur_sum = prev_sum + root->val;
        cur_path.emplace_back(root->val);

        if (root->left == nullptr && root->right == nullptr && cur_sum == target) {

            paths.emplace_back(cur_path);

        } else {

            PathSumIIHelper(root->left, paths, cur_path, cur_sum, target);
            PathSumIIHelper(root->right, paths, cur_path, cur_sum, target);

        }
    }
}

vector<vector<int>> PathSumII(TreeNode* root, int target) {
    vector<vector<int>> paths;
    vector<int> init_path = {};
    PathSumIIHelper(root, paths, init_path, 0, target);
    return paths;
}
