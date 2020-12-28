## flatten binary to linked list (medium)

**solution 1**
```cpp
class Solution {
private:
  TreeNode* helper(TreeNode *root) {
    if (!root) return NULL;
    auto leftEnd = helper(root->left), rightEnd = helper(root->right), right = root->right;
    root->right = root->left;
    root->left = NULL;
    if (leftEnd) leftEnd->right = right;
    else root->right = right;
    return rightEnd ? rightEnd : (leftEnd ? leftEnd : root);
  }
public:
  void flatten(TreeNode* root) {
    helper(root);
  }
};
```
**solution 2**
```cpp
class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode *prev = NULL;
    while (!s.empty()) {
      root = s.top();
      s.pop();
      if (prev) {
        prev->left = NULL;
        prev->right = root;
      }
      prev = root;
      if (root->right) s.push(root->right);
      if (root->left) s.push(root->left);
    }
  }
};
```
