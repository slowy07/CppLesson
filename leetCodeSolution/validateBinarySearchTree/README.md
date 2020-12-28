## validate binary search tree (medium)


**solution 1 pre order tranversal**
```cpp
class Solution {
private:
  bool isValidBST(TreeNode *root, TreeNode *lb, TreeNode *rb) {
    if (!root) return true;
    if ((lb && root->val <= lb->val) || (rb && root->val >= rb->val)) return false;
    return isValidBST(root->left, lb, root) && isValidBST(root->right, root, rb);
  }
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
};
```
**solution 2 in-order tranvelsal**
```cpp
class Solution {
private:
  TreeNode *last = NULL;
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    if (!isValidBST(root->left) || (last && last->val >= root->val)) return false;
    last = root;
    return isValidBST(root->right);
  }
};
```
