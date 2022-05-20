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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root->val == key){
            return helper(root);
        }
        
        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                // go left
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    return dummy;
                }
                else root = root->left;
            }
            else{
                // go right
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    return dummy;
                }
                else root = root->right;
            }
        }
        
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root){

        // root is the node we are going to delete and we have to return the new root

        // if the node we are deleting does not have left we return the right
        if(root->left == NULL){
            return root->right;
        }
        
        // if the node we are deleting does not have right we return the left
        if(root->right == NULL){
            return root->left;
        }

        // we are having both nodes
        // we will send the left node as the root
        // so we will need to relocate the right part
        // we will traverse all the way to the right of the left part of the root and connect it to the right part of the root that will be deleted
        // then return the roots left as the right part if already relocated
        
        TreeNode* rightNode = root->right;

        TreeNode* temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = rightNode;
        
        return root->left;
    }
    
    
};