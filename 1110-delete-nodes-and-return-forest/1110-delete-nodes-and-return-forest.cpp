/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(TreeNode* root, unordered_set<int>& set,
                  vector<TreeNode*> &res) {
        if (root == NULL)
            return NULL;

        root->left = fun(root->left, set, res);
        root->right = fun(root->right, set, res);
        if (set.find(root->val) != set.end()) {
            if (root->left != NULL)
                res.push_back(root->left);
            if (root->right != NULL)
                res.push_back(root->right);
            return NULL;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> set;
        for (auto it : to_delete) {
            set.insert(it);
        }
       root= fun(root, set, res);

        if (root != NULL)
            res.push_back(root);

        return res;
    }
};