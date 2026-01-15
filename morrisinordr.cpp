void morrisInorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left == NULL) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL) {
                prev->right = curr;      // make thread
                curr = curr->left;
            } else {
                prev->right = NULL;      // remove thread
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
    
    
// 🚦 EXACT RULES (YAAD RAKHO)
// Jab curr exist kare:
// ✅ CASE 1: curr->left == NULL

// 👉 Matlab:

// Left side kuch nahi

// Ye node inorder me abhi print hogi

// Steps:

// Print curr->val

// curr = curr->right

// if (curr->left == NULL) {
//     cout << curr->val << " ";
//     curr = curr->right;
// }

// ✅ CASE 2: curr->left != NULL

// 👉 Matlab:

// Left subtree exist karta hai

// Pehle uska rightmost node (predecessor) dhoondo

// prev = curr->left;
// while (prev->right != NULL && prev->right != curr) {
//     prev = prev->right;
// }


// Ab 2 sub-cases:

// 🔹 CASE 2A: prev->right == NULL

// 👉 Matlab:

// Pehli baar aaye ho

// Abhi left subtree me jaana hai

// Steps:

// prev->right = curr (temporary thread)

// curr = curr->left

// prev->right = curr;
// curr = curr->left;


// 🧠 Ye recursion ka “return address” hai

// 🔹 CASE 2B: prev->right == curr

// 👉 Matlab:

// Left subtree complete ho chuka

// Ab wapas aaye ho

// Steps:

// Thread hatao → prev->right = NULL

// Print curr->val

// curr = curr->right

// prev->right = NULL;
// cout << curr->val << " ";
// curr = curr->right;


