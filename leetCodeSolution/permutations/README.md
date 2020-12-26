## permutation (medium)
**solution 1 (dfs)**
```cpp
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
```
**solution 2 (next permutation)**
```cpp
class Solution {
    bool nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (j > i && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return i >= 0;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans { nums };
        while (nextPermutation(nums)) ans.push_back(nums);
        return ans;
    }
};
```
