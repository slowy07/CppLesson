class Solution {
private:
    int ans = INT_MIN;
    int postOrder(TreeNode *root) {
        if (!root) return INT_MIN;
        int L = max(0, postOrder(root->left)), R = max(0, postOrder(root->right));
        ans = max(ans, L + R + root->val);
        return root->val + max(L, R);
    }
public:
    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
