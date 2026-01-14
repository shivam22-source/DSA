// Approach:
// 1. Postorder traversal gives the root at the end.
// 2. Using inorder traversal, we find how many nodes
//    belong to the left subtree.
// 3. Left subtree size helps us split postorder array.
// 4. Recursively build left and right subtrees
//    using calculated ranges.
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int posStart, int posEnd) {

        // Base case
        if (inStart > inEnd || posStart > posEnd)
            return NULL;

        // Root comes from last element of postorder
        TreeNode* root = new TreeNode(postorder[posEnd]);

        int rootIndex = mp[root->val];
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = build(
            inorder,
            inStart,
            rootIndex - 1,
            postorder,
            posStart,
            posStart + leftSize - 1
        );

        // Build right subtree
        root->right = build(
            inorder,
            rootIndex + 1,
            inEnd,
            postorder,
            posStart + leftSize,
            posEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(
            inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1
        );
    }
};
