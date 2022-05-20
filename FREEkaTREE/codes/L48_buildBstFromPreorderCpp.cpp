// preorder => root left right


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);

        // for left current root is the max bound
        root->left = build(A, i, root->val);

        // for right prev bound is the mx bound
        root->right = build(A, i, bound);
        return root;
    }
};
