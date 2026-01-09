// Agar dono nodes NULL hain → symmetric (true)

// Agar ek NULL aur doosra NULL nahi → symmetric nahi (false)

// Agar dono nodes ki value same hai

// Phir recursively check karo:

// left subtree ka left ↔ right subtree ka right

// left subtree ka right ↔ right subtree ka left

// Agar dono recursive calls true hain → tree symmetric

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Case 1: dono null hain
        if (left == NULL && right == NULL) return true;

        // Case 2: ek null, ek nahi
        if (left == NULL || right == NULL) return false;

        // Case 3: values same honi chahiye
        if (left->val != right->val) return false;

        // Case 4: mirror check
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};
