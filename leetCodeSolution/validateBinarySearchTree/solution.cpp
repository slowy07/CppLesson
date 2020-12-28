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
