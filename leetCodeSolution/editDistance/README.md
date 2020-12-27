## edit distance (hard)


**solution 1 DP**
```cpp
class Solution {
public:
    int minDistance(string A, string B) {
        if (A.empty() || B.empty()) return max(A.size(), B.size());
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min({ dp[i][j], dp[i][j + 1], dp[i + 1][j] });
            }
        }
        return dp[M][N];
    }
};
```
```cpp
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
        return dp[M][N];
    }
};
```
**solution 2 space optimization**
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        if (M < N) {
            swap(word1, word2);
            swap(M, N);
        }
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = i;
        for (int i = 1; i <= M; ++i) {
            dp[i % 2][0] = i;
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min(min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]), dp[(i - 1) % 2][j - 1]);
            }
        }
        return dp[M % 2][N];
    }
};
```
