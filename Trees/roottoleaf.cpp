// DFS traversal to build root-to-leaf paths
// We use backtracking to remove the current node
// after exploring its children

void dfs(TreeNode* root, string &path) {

    // base case
    if (!root) return;

    // store current length for backtracking
    int len = path.size();

    // add current node value
    path += to_string(root->val);

    // if leaf node, save the path
    if (!root->left && !root->right) {
        ans.push_back(path);
    }
    else {
        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }

    // remove current node before returning
    path.erase(len);
}
