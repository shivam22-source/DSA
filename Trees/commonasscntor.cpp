// LCA logic:
// If current node is p or q, return it
// If p and q are found in different subtrees,
// current node becomes the lowest common ancestor

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;

    if (root == p || root == q)
        return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}
