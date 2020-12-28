## interleaving string (hard)

**solution 1 DP top-down (DFS + memo)**
```cpp
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &a, string &b, string &c, int i, int j) {
        if (i == M && j == N) return 1;
        if (m[i][j] != 0) return m[i][j];
        int val = -1;
        if (i < M && a[i] == c[i + j]) val = dfs(a, b, c, i + 1, j);
        if (val != 1 && j < N && b[j] == c[i + j]) val = dfs(a, b, c, i, j + 1);
        return m[i][j] = val;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s1, s2, s3, 0, 0) == 1;
    }
};
```
**solution 2 DP bottom-up**
```cpp
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i < M && a[i] == c[i + j]) dp[i][j] |= dp[i + 1][j];
                if (j < N && b[j] == c[i + j]) dp[i][j] |= dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
```
**solution 3 DP with space optimization**
```cpp
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<int> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i == M && j == N) dp[j] = true;
                else dp[j] = (i < M && a[i] == c[i + j] && dp[j])
                    || (j < N && b[j] == c[i + j] && dp[j + 1]);
            }
        }
        return dp[0];
    }
};
```
