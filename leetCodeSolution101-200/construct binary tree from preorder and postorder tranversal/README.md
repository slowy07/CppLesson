## construct binary tree from preorder and postorder tranversal (medium)

**solution 1**
```cpp
class Solution {
private:
  TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int pi, int pe) {
    if (is > ie) return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);
    int leftLen = find(inorder.begin() + is, inorder.begin() + ie, postorder[pe]) - inorder.begin() - is;
    root->left = buildTree(inorder, postorder, is, is + leftLen - 1, pi, pi + leftLen - 1);
    root->right = buildTree(inorder, postorder, is + leftLen + 1, ie, pi + leftLen, pe - 1);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }
};
```
**solution 2**
```cpp
class Solution {
private:
  unordered_map<int, int> m;
  TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int pi, int pe) {
    if (is > ie) return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);
    int leftLen = m[postorder[pe]] - is;
    root->left = buildTree(inorder, postorder, is, is + leftLen - 1, pi, pi + leftLen - 1);
    root->right = buildTree(inorder, postorder, is + leftLen + 1, ie, pi + leftLen, pe - 1);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
      return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }
};
```
