## subsets 2 (medium)

**solution 1**
```cpp
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i, vector<int> &v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        dfs(nums, i + 1, v);
        v.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        dfs(nums, i + 1, v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, v);
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int start, vector<int> &sub, int len) {
        if (!len) {
            ans.push_back(sub);
            return;
        }
        for (int i = start; i <= nums.size() - len; ++i) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, len - 1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for (int i = 0; i <= nums.size(); ++i) dfs(nums, 0, v, i);
        return ans;
    }
};
```
**solution 3**
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int cnt = 0, n = nums[i], len = ans.size();
            while (i < nums.size() && nums[i] == n) ++cnt, ++i;
            for (int j = 0; j < len; ++j) {
                vector<int> sub = ans[j];
                for (int k = 0; k < cnt; ++k) {
                    sub.push_back(n);
                    ans.push_back(sub);
                }
            }
        }
        return ans;
    }
};
```
