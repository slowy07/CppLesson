## wildcard matching (hard)

**solution 1 (DP top down)**
```cpp
class Solution {
    int M, N;
    vector<vector<int>> m;
    bool isMatch(string &s, string &p, int i, int j) {
        if (m[i][j] != -1) return m[i][j];
        int &ans = m[i][j];
        for (; j < N; ++j) {
            if (p[j] != '*' && i >= M) return ans = false;
            if (p[j] == '?') ++i;
            else if (p[j] == '*') {
                while (j + 1 < N && p[j + 1] == '*') ++j;
                for (int k = 0; i + k <= M; ++k) {
                    if (isMatch(s, p, i + k, j + 1)) return ans = true;
                }
            } else if (s[i++] != p[j]) return ans = false;
        }
        return ans = i >= M;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1, -1));
        return isMatch(s, p, 0, 0);
    }
};
```
**solution 2 (DP bottom up)**
```cpp
class Solution { public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i > 0 && (p[j - 1] == '?' || s[i - 1] == p[j - 1])) dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
            }
        }
        return dp[M][N];
    }
};
```
**solution 3**
```cpp
class Solution { public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size(), star = -1, ss = 0, i = 0, j = 0;
        while (i < M) {
            if (p[j] == '?' || p[j] == s[i]) {
                ++i;
                ++j;
                continue;
            }
            if (p[j] == '*') {
                star = j++;
                ss = i;
                continue;
            }
            if (star != -1) {
                j = star + 1;
                i = ++ss;
                continue;
            }
            return false;
        }
        while (p[j] == '*') ++j;
        return j == N;
    }
};
```
