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


bool isBALANCED(struct *root){

    //get the height for a node's left and right
    int lh = height(root->left);
    int rh = height(root->right);

    //base condition, as recursions goes on it will reach the null after root nodes
    // once there, code should return true; means isBALANCED(root->left)==true & isBALANCED(root->right)==true to be true
    // thus returning true upwards
    if(root == NULL){
        return true;
    }

    //condition for checking if balanced is true
    if(abs(lh-rh)<=1 && isBALANCED(root->left)==true && isBALANCED(root->right)==true){
        return true;
    }
    //if at any point, any of these defined conditions fail, means BST not balanced retuen false to caller method 
    return false;
}

//TC-O(N^2) worst caseá