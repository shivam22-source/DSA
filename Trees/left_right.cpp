///left-view
// We traverse the tree level by level using BFS.

// For each level:

// The first node encountered (i == 0) is visible from the left.

// Queue ensures correct level order traversal.

// Time Complexity: O(n)

// Space Complexity: O(n) (queue)

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();   // number of nodes at current level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // first node of this level = left view
                if (i == 0)
                    ans.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};

//right view


// BFS traversal gives us nodes level by level.

// For each level:

// The last node (i == size - 1) is visible from the right.

// Same traversal, only condition differs.

// Time Complexity: O(n)

// Space Complexity: O(n)

class Solution {
public:
    vector<int> rightView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();   // number of nodes at this level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // last node of this level = right view
                if (i == size - 1)
                    ans.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
