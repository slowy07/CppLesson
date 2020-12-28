class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int cnt = q.size();
            ans.emplace_back();
            while (cnt--) {
                root = q.front();
                q.pop();
                ans.back().push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
