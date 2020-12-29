## sum root to leaf number (medium)

**solution 1 recursive pre order tranversal**
```cpp
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
```
**solution 2 iterative pre order tranversal**
```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> s;
        s.emplace(root, 0);
        int ans = 0;
        while (s.size()) {
            auto p = s.top();
            root = p.first;
            int sum = p.second * 10 + root->val;
            s.pop();
            if (!root->left && !root->right) ans += sum;
            if (root->right) s.emplace(root->right, sum);
            if (root->left) s.emplace(root->left, sum);
        }
        return ans;
    }
};
```
