## binary tree zigzag level order tranversal (medium)

**solution 1**
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> lv;
            while (cnt--) {
                root = q.front();
                q.pop();
                lv.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (!l2r) reverse(begin(lv), end(lv));
            ans.push_back(lv);
            l2r = !l2r;
        }
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_front(root);
        bool l2r = true;
        while (q.size()) {
            int cnt = q.size();
            ans.emplace_back();
            while (cnt--) {
                if (l2r) {
                    root = q.front();
                    q.pop_front();
                } else {
                    root = q.back();
                    q.pop_back();
                }
                ans.back().push_back(root->val);
                if (l2r) {
                    if (root->left) q.push_back(root->left);
                    if (root->right) q.push_back(root->right);
                } else {
                    if (root->right) q.push_front(root->right);
                    if (root->left) q.push_front(root->left);
                }
            }
            l2r = !l2r;
        }
        return ans;
    }
};
```
