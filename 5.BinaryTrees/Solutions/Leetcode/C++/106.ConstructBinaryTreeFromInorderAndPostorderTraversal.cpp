#include "../Debug.h"
using namespace std;


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	unordered_map<int, size_t> inorder_map;
	for (size_t i = 0; i < inorder.size(); i++) {  
		inorder_map[inorder[i]] = i; 
	}
	
	return buildTreeHelper(inorder, postorder, inorder_map, 0, postorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(
	vector<int>& inorder, 
	vector<int>& postorder,
	unordered_map<int, size_t>& inorder_map,
	int postorder_start, int postorder_end,
	int inorder_start, int inorder_end) {
		
		if (postorder_start > postorder_end || inorder_start > inorder_end) {
			return nullptr;
		}
		
		int rootval = postorder[postorder_end],
			root_inorder_idx = inorder_map[rootval],
			leftsubtree_size = root_inorder_idx - inorder_start;
		
		TreeNode* subtree_root = new TreeNode(rootval);
		subtree_root->left = buildTreeHelper (
			inorder,
			postorder,
			inorder_map,
			postorder_start, postorder_start + leftsubtree_size - 1,
			inorder_start, inorder_start + leftsubtree_size - 1
		);
		
		subtree_root->right = buildTreeHelper (
			inorder,
			postorder,
			inorder_map,
			postorder_start + leftsubtree_size, postorder_end - 1,
			root_inorder_idx + 1, inorder_end
		);
		
		return subtree_root;
}
