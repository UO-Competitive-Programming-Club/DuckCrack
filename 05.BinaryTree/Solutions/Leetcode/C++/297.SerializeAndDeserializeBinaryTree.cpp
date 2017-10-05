#include "../Debug.h"
using namespace std;

string serialize(TreeNode* root);
void serializeHelper(TreeNode* root, string& str);

TreeNode* deserialize(string data);
TreeNode* deserializeHelper(vector<string>& A, size_t& i);

string serialize(TreeNode* root) {
	string str;
	serializeHelper(root, str);
	return str;
}

void serializeHelper(TreeNode* root, string& str) {
	if (root) {
		str += to_string(root->val) + ',';
		serializeHelper(root->left, str);
		serializeHelper(root->right, str);
	} else {
		str += "null,";
	}
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	vector<string> A = split(data, ',');
	size_t i = 0;
	return deserializeHelper(A, i);
}

TreeNode* deserializeHelper(vector<string>& A, size_t& i) {
	if (A[i] == "null" || i >= A.size()) {
		return nullptr;
	}

	TreeNode* cur_node = new TreeNode(stoi(A[i]));

	auto left = deserializeHelper(A, ++i),
		 right = deserializeHelper(A, ++i);

	cur_node->left = left;
	cur_node->right = right;

	return cur_node;
}
