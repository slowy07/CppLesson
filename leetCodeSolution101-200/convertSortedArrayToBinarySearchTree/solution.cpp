class Solution {
private:
  TreeNode* build(vector<int> &nums, int begin, int end) {
    if (begin >= end) return NULL;
    int mid = (begin + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, begin, mid);
    root->right = build(nums, mid + 1, end);
    return root;
  }
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size());
  }
};
