// Approach:
// 1. First, store parent of each node using BFS.
// 2. Find the node with value = start.
// 3. Perform BFS from the start node.
// 4. At each second, fire spreads to:
//    - left child
//    - right child
//    - parent
// 5. If at least one new node burns in a level,
//    increment time.
// 6. When BFS ends, time is the answer.



class Solution {
public:
    // Step 1: Store parent pointers
    void mark(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    // Step 2: Find start node using value
    TreeNode* findNode(TreeNode* root, int start) {
        if (!root) return NULL;
        if (root->val == start) return root;

        TreeNode* left = findNode(root->left, start);
        if (left) return left;

        return findNode(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mark(root, parent_track);

        TreeNode* target = findNode(root, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int time = 0;

        // Step 3: BFS burn process
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // left
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    burned = true;
                }

                // right
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    burned = true;
                }

                // parent
                TreeNode* parent = parent_track[curr];
                if (parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                    burned = true;
                }
            }

            if (burned) time++;
        }

        return time;
    }
};
