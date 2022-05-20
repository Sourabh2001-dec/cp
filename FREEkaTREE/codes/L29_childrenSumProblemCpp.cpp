// sum of the children of a node should be equal to the parent
// You can increment the value of children by 1 for any number of times
// sol - if the sum of the children is less than the parent then update their value to be equal to the parent  and update the value of parent else update the value of parent to be the sum

void reorder(BinaryTreeNode < int > * root) {
    if(root == NULL) return; 

    // get the sum of the children

    int child = 0;
    if(root->left) {
        child += root->left->data; 
    }
    if(root->right) {
        child += root->right->data; 
    }
    
    // if sum is greater than parent
    if(child >= root->data) root->data = child; 
    // if sum is lesser than parent
    else {
        if(root->left) root->left->data = root->data; 
        else if(root->right) root->right->data = root->data; 
    }
    
    reorder(root->left); 
    reorder(root->right); 
    
    // when comming back after traversing left and right we sum and set value of the root
    int tot = 0; 
    if(root->left) tot += root->left->data; 
    if(root->right) tot+= root->right->data; 
    if(root->left || root->right) root->data = tot;  
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root); 
}  
