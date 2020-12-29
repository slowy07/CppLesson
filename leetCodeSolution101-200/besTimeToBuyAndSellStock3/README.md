## best time to buy and sell stock 3 (hard)

**solution 1**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for (int k = 1; k < 3; ++k) {
            for (int i = 1; i < N; ++i) {
                int maxVal = INT_MIN;
                for (int j = 0; j < i; ++j) maxVal = max(maxVal, dp[k - 1][j] - A[j]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[2][N];
    }
};
```

**solution 2 DP space optimization**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(3));
        vector<int> maxVal(3, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k < 3; ++k) {
                maxVal[k] = max(maxVal[k], dp[i][k - 1] - A[i]);
                dp[i + 1][k] = max(dp[i][k], A[i] + maxVal[k]);
            }
        }
        return dp[N][2];
    }
};
```
