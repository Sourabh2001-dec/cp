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

// ?? Inorder Traversal of Binary Search Tree gives nodes in ascending order

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        solve(root, cnt, ans, k);
        return ans;
    }
    
    void solve(TreeNode* node, int &cnt, int &ans, int &k){
        if(node == NULL) return;
        
        solve(node->left, cnt, ans, k);
        cnt++;
        if(cnt == k) {
            ans = node->val;
            return;
        }
        solve(node->right, cnt, ans, k);
    }
};