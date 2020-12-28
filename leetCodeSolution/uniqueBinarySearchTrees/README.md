## unique binary search trees (medium)

**solution 1 DP bottom-up**
```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
```
**solution 2 DP top-down**
```cpp
class Solution {
    vector<int> memo;
    int dp(int n) {
        if (memo[n]) return memo[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += dp(i) * dp(n - i - 1);
        return memo[n] = ans;
    }
public:
    int numTrees(int n) {
        memo.assign(n + 1, 0);
        memo[0] = 1;
        return dp(n);
    }
};
```
```cpp
//catalan number
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1, i;
        for (i = 1; i <= n; ++i) ans = ans * (i + n) / i;
        return ans / i;
    }
};
```
