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

// we are checking if every node in the left is smaller than current and larger then current in the right part
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long int minVal, long int maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return isValidBST(root->left,minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};