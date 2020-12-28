## same tree (easy)

**solution 1**
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (!p && !q) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
```
