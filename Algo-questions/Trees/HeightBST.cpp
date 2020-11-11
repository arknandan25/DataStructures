int height(struct *root){
    if(root == NULL){
        return 0;
    }else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }else{
            return right_height+1;
        }
    }
}

//TC-O(N) N is the number of nodes
//SC-O(d) d is the depth of the tree