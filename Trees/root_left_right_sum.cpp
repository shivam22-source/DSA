/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root)return false;
        //top to botom
int child=0;
if(root->left)child+=root->left->val;
if(root->right)child+=root->right->val;

if(child>root->val)root->val=child;
else{
   if(root->left)root->left->val=root->val;
if(root->right)root->right->val=root->val;

}
//deeper
checkroot(root->left);
checkroot(root->right);
//bottom to top 
int total=0;
if(root->left)total+=root->left->val;
if(root->right)total+=root->right->val;
if(root->left||root->right){
    root->val=total;          ///dhyaaan rkhna h ki leaf node ko n update kreee
}

    }
};