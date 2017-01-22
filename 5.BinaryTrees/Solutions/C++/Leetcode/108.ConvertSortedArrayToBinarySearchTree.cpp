#include "../Debug.h"
using namespace std;

TreeNode * SortedArrayToBSTHelper(const vector<int>& nums, int begin, int end);

TreeNode* SortedArrayToBST(const vector<int>& nums) {
    return SortedArrayToBSTHelper(nums, 0, nums.size());
}

TreeNode * SortedArrayToBSTHelper(const vector<int>& nums, int begin, int end) {
    if (begin > end) {
        return nullptr;
    }

    if (begin == end) {
        return new TreeNode(nums[begin]);
    }

    /* integer division ceilling it only works with positive numbers */
    int middle = (begin + end) / 2 + ((begin + end) % 2);
    TreeNode* leftchild = SortedArrayToBSTHelper(nums, begin, middle - 1),
            * rightchild = SortedArrayToBSTHelper(nums, middle + 1, end);

    TreeNode* root = new TreeNode(nums[middle]);
    root->left = leftchild;
    root->right = rightchild;

    return root;
}
