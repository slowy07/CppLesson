class Solution {
private:
    vector<TreeNode*> generateTrees(int first, int last) {
        if (first > last) return { NULL };
        vector<TreeNode*> v;
        for (int i = first; i <= last; ++i) {
            auto lefts = generateTrees(first, i - 1);
            auto rights = generateTrees(i + 1, last);
            for (auto left : lefts) {
                for (auto right : rights) {
                    v.push_back(new TreeNode(i));
                    v.back()->left = left;
                    v.back()->right = right;
                }
            }
        }
        return v;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        return generateTrees(1, n);
    }
};
