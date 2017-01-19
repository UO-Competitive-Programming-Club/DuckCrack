#include "../Debug.h"

using namespace std;

int minDepth(TreeNode* root) {
	if (root == nullptr) { return 0; }  
	
	if (root->left == nullptr && root->right == nullptr) { return 1; }

	auto left = (root->left == nullptr) ? INT_MAX : minDepth(root->left) + 1,
		 right = (root->right == nullptr) ? INT_MAX : minDepth(root->right) + 1;

	return min(left, right);
}
