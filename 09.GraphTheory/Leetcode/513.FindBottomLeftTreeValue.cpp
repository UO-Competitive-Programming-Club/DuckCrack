#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> frontier; frontier.push(root);
        vector<int> level; 
        int left_item = root->val;
        while (!frontier.empty()) {
            int qlen = frontier.size();
            left_item = frontier.front()->val;
            for (int i = 0; i < qlen; i++) {
                TreeNode* cn = frontier.front(); frontier.pop();
                if (cn->left) frontier.push(cn->left);
                if (cn->right) frontier.push(cn->right);
            }
        }
       
        return left_item;
    }
};
