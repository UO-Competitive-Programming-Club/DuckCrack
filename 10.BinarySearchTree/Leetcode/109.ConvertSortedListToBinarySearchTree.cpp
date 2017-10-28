TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nodes;
    while (head) {
        nodes.push_back(head->val);
        head = head->next;
    }
    
    return helper(nodes, 0, nodes.size() - 1);
}

TreeNode* helper(vector<int>& nodes, int left, int right) {
    // cout << "left: " << left << " right " << right << endl;
    if (left > right) { return NULL; }
    if (left == right) { return new TreeNode(nodes[left]); }
    
    int root_index = (left + right + 1) / 2;
    
    TreeNode * new_node = new TreeNode(nodes[root_index]);
            
    new_node->left = helper(nodes, left, root_index - 1);
    new_node->right = helper(nodes, root_index + 1, right);

    return new_node;
}
