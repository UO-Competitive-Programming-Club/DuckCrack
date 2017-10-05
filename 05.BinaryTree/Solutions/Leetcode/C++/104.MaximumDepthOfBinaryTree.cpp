#include "../Debug.h"

using namespace std;

int maxDepth(TreeNode* root) {
	if (root == nullptr) { return 0; }  
	
	auto left = maxDepth(root->left) + 1,
		 right = maxDepth(root->right) + 1;

	return max(left, right);
}
