class Solution {
    int ans = 0;
    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) ans += sum;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
