// VALIDATE BINARY SEARCH TREE
// ----------------------------
// Idea:
// Each node must lie in a valid range (min , max)
//
// Rule:
// if root->val <= min OR root->val >= max → NOT a BST
//
// Left subtree:
//   max becomes root->val
//
// Right subtree:
//   min becomes root->val

bool isValid(TreeNode* root, long minVal, long maxVal) {

    // Base case: empty tree is valid BST
    if (!root) return true;

    // If current value breaks BST range
    if (root->val <= minVal || root->val >= maxVal)
        return false;

    // Check left subtree
    // Allowed range: (minVal , root->val)
    bool leftValid = isValid(root->left, minVal, root->val);

    // Check right subtree
    // Allowed range: (root->val , maxVal)
    bool rightValid = isValid(root->right, root->val, maxVal);

    // Tree is BST only if both sides are valid
    return leftValid && rightValid;
}

bool isValidBST(TreeNode* root) {

    // Initial range: (-infinity , +infinity)
    return isValid(root, LONG_MIN, LONG_MAX);
}
