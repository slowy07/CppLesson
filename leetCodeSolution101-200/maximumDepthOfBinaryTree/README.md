## maximum depth of binary tree (easy)

**solution 1**
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
```
