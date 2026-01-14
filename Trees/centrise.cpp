// We use level order traversal (BFS).
// For each node:
// - If node is NULL, add '#' to the string.
// - Otherwise, add its value and push its children.
// This preserves exact tree structure.
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string s = "";

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                s += "#,";
                continue;
            }

            s += to_string(curr->val) + ",";

            // push children even if they are NULL
            q.push(curr->left);
            q.push(curr->right);
        }

        return s;
    }
