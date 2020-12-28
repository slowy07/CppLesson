class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int d = INT_MAX;
        if (root->left) d = minDepth(root->left);
        if (root->right) d = min(d, minDepth(root->right));
        return 1 + d;
    }
};
