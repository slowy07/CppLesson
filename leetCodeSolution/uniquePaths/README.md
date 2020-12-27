## unique paths

**solution 1 DP**
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) dp[j] += dp[j + 1];
        }
        return dp[0];
    }
};
```
**solution 2 maths**
``(m + n - 2) ! / ((m - 1)! *(n - 1)!)``
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = 1; i <= n - 1; ++i) ans = ans * (m - 1 + i) / i;
        return ans;
    }
};
```
