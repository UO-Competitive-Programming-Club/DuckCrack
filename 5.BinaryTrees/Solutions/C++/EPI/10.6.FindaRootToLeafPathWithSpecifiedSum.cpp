#include "../Debug.h"

using namespace std; 

bool HasPathSumHelper(TreeNode* root, int prev_sum, int target_sum);

bool hasPathSum(TreeNode* root, int target) {
	return HasPathSumHelper(root, 0, target);
}

bool HasPathSumHelper(TreeNode* root, int prev_sum, int target_sum) {
	if (root == nullptr) {
		return false;
	}

	int cur_sum = prev_sum + root->val;
	if (root->left == nullptr && root->right == nullptr && cur_sum == target_sum) {
		return true;
	}
	
	return HasPathSumHelper(root->left, cur_sum, target_sum) || HasPathSumHelper(root->right, cur_sum, target_sum);
}
