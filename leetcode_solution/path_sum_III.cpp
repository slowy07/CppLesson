/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    int f(TreeNode *root, int tar){
        if(!root) return 0;
        return (tar==root->val) + f(root->left,(1ll)*tar-root->val) + f(root->right,(1ll)*tar-root->val);
    }
    int pathSum(TreeNode* root, int tar) {
        if(!root) return 0;
        return f(root,tar) + pathSum(root->left,tar) + pathSum(root->right,tar);
    }
};
