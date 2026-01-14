// We rebuild the tree using BFS.
// Read values one by one:
// - First value becomes root.
// - For every node popped from queue,
//   assign left and right children using next values.
// '#' represents NULL nodes.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            if (getline(ss, val, ',')) {
                if (val != "#") {
                    curr->left = new TreeNode(stoi(val));
                    q.push(curr->left);
                }
            }

            // right child
            if (getline(ss, val, ',')) {
                if (val != "#") {
                    curr->right = new TreeNode(stoi(val));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};
