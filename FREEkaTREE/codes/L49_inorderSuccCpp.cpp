// when at a node we check if the current nodes value is greater than value we are finding and we go left in hope we find a node which is just greater than the value we are looking for

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        
        while (root != NULL) {
            // if current nodes value is less than the value we are looking we go right
            if (p->val >= root->val) {
                root = root->right;
            } else {
            // current nodes value is greatere than the value we are looking so we save the current node as the successor and move left 
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
};
