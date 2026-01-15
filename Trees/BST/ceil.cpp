// key and i want closest val which saisfy key<=val <-ceil
while(root){
    if(key==root->val){
        ceil=root->val;
        return ceil;
    }
     if (key>root->val){
root=root->right;
     }
     else {ceil=root->val;
    root=root->left;}
     
} //TC->O(N)