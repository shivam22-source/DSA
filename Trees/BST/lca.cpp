// LOWEST COMMON ANCESTOR IN BST
// -----------------------------
// Idea (BST property based):
//
// 1) If root->val is GREATER than both p & q
//    → both lie in LEFT subtree → go left
//
// 2) If root->val is LESS than both p & q
//    → both lie in RIGHT subtree → go right
//
// 3) If one is smaller & one is greater
//    → current root is the LCA
//
// 4) If root->val equals p or q
//    → root itself is LCA

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    // Base case
    if (!root) return NULL;

    // If root value is greater than both p and q
    // Move to left subtree
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If root value is smaller than both p and q
    // Move to right subtree
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // If one value is on left and the other on right
    // OR root equals p or q
    // This root is the lowest common ancestor
    return root;
}
