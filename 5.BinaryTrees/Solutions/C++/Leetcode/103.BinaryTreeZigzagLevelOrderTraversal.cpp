#include "../Debug.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}

	result.push_back({root->val});
	stack<TreeNode*> S0, S1;
	S0.push(root);
	int level = 0;

	while (!S0.empty() || !S1.empty()) {
		vector<int> next_level_result;
		for (size_t i = 0; i < result[level].size(); i++) {
			TreeNode* parent;
			if (level % 2 == 0) {
				parent = S0.top();
				S0.pop();
				if (parent->right) {
					next_level_result.push_back(parent->right->val);
					S1.push(parent->right);
				}
				
				if (parent->left) {
					next_level_result.push_back(parent->left->val);
					S1.push(parent->left);
				}
			} else {
				parent = S1.top();
				S1.pop();

				if (parent->left) {
					next_level_result.push_back(parent->left->val);
					S0.push(parent->left);
				}
				
				if (parent->right) {
					next_level_result.push_back(parent->right->val);
					S0.push(parent->right);
				}              
			}
		}

		if (!next_level_result.empty()) {
			result.push_back(next_level_result);
		}
		
		level++;
	}

	return result;
}
