## maximum sub array (easy)

**solution 1 rolling sum + greedy**
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minSum = 0, ans = INT_MIN;
        for (int n : nums) {
            ans = max(ans, n - minSum);
            minSum = min(minSum, n);
        }
        return ans;
    }
};
```
**solution 2 DP**
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size();
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) ans = max(ans, dp[i + 1] = max(dp[i], 0) + nums[i]);
        return ans;
    }
};
```
**solution 3 DP**
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += max(nums[i - 1], 0);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
```
**solution 4 DP**
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = INT_MIN;
        for (int n : nums) {
            cur = max(cur, 0) + n;
            ans = max(ans, cur);
        }
        return ans;
    }
};
```
**solution 5 divide and conquer**
```cpp
class Solution {
private:
    int crossSum(vector<int>& nums, int L, int R, int p) {
        if (L == R) return nums[L];
        int left = INT_MIN, right = INT_MIN, i, sum;
        for (i = p, sum = 0; i >= L; --i) left = max(left, sum += nums[i]);
        for (i = p + 1, sum = 0; i <= R; ++i) right = max(right, sum += nums[i]);
        return left + right;
    }

    int helper(vector<int>& nums, int L, int R) {
        if (L == R) return nums[L];
        int p = (L + R) / 2;
        int left = helper(nums, L, p);
        int right = helper(nums, p + 1, R);
        int cross = crossSum(nums, L, R, p);
        return max(left, max(right, cross));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
```
