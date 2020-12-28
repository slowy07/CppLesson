## minimum depth of binary tree (easy)

**solution 1 BFS**

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto node = q.front();
                q.pop();
                if (!node->left && !node->right) return ans;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++ans;
        }
        return -1;
    }
};
```
**solution 2 DFS**
```cpp
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
```
