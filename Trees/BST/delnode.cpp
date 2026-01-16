// DELETE NODE IN BST (KEY GIVEN)
// --------------------------------
// Idea: When node has 2 children
// 1) Break the node
// 2) Join left subtree to leftmost of right subtree
// 3) Return right subtree

TreeNode* deleteNode(TreeNode* root, int key) {

    // Base case: empty tree
    if (!root) return NULL;

    // If key is smaller, go left
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }

    // If key is larger, go right
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }

    // Key found -> start deletion
    else {

        // CASE 1: No left child
        // Directly return right subtree (break happens here)
        if (!root->left)
            return root->right;

        // CASE 2: No right child
        // Directly return left subtree
        if (!root->right)
            return root->left;

        // CASE 3: Both children present
        // --------------------------------

        // Step 1: Store right subtree
        TreeNode* rightChild = root->right;

        // Step 2: Find leftmost node of right subtree
        // (smallest element in right subtree)
        TreeNode* temp = rightChild;
        while (temp->left != NULL)
            temp = temp->left;

        // Step 3: Join
        // Attach left subtree to leftmost node
        // Safe because:
        // left subtree values < temp value
        temp->left = root->left;

        // Step 4: Return right subtree as new root
        return rightChild;
    }

    // Return updated root
    return root;
}
