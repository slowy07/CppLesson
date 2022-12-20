class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> min_bst(cbegin(nums), cbegin(nums) + k);
        auto mid = next(cbegin(min_bst), k / 2);
        vector<double> result = {((*mid) + *prev(mid, 1 - k % 2)) / 2};
        for (int i = k; i < size(nums); ++i) {
            min_bst.emplace(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            }
            if (nums[i - k] <= *mid) {
                ++mid;
            }
            min_bst.erase(min_bst.lower_bound(nums[i - k]));
            result.emplace_back(((*mid) + *prev(mid, 1 - k % 2)) / 2);
        }
        return result;
    }
};
