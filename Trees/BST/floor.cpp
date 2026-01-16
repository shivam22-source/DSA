// key and i want closest val which saisfy key>=val <-ceil
while(root){
    if(key==root->val){
        floor=root->val;
        return floor;
    }
     if (key<root->val){
root=root->left;
     }
     else {floor=root->val;
    root=root->right;}
     
} //TC->O(N)