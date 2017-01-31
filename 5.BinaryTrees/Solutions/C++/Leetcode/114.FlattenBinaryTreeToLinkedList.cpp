#include "../Debug.h"

using namespace std;

TreeNode* flattenHelper(TreeNode* root);
void flatten(TreeNode* root) {
	flattenHelper(root);
}

TreeNode* flattenHelper(TreeNode* root) {
	if (!root || (!root->left && !root->right)) {
		return root;
	}

	auto left_flattened_tail = flattenHelper(root->left),
		 right_flattened_tail = flattenHelper(root->right);

	if (root->left) {
		auto temp = root->right;
		left_flattened_tail->right = temp;
		root->right = root->left;
		root->left = nullptr;
	}
	
    /* handle the case when the right child is nullptr */
	if (!right_flattened_tail) {
		right_flattened_tail = left_flattened_tail;
	}

	return right_flattened_tail;
}
