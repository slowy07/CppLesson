## regular expression matching (hard)
**solution 1**
```cpp
class Solution {
private:
    inline bool matchChar(string &s, int i, string &p, int j) {
        return p[j] == '.' ? i < s.size() : s[i] == p[j];
    }
    bool isMatch(string s, int i, string p, int j) {
        if (j == p.size()) return i == s.size();
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool ans = false;
            while (!(ans = isMatch(s, i, p, j + 2))
            && matchChar(s, i, p, j)) ++i;
            return ans;
        } else {
            return matchChar(s, i, p, j) && isMatch(s, i + 1, p, j + 1);
        }
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};
```
**solution 2**
```cpp
class Solution {
    int M, N;
    bool dfs(string &s, string &p, int i, int j) {
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                if (dfs(s, p, i, j + 2)) return true;
                while (i < M && (p[j] == '.' || s[i] == p[j])) {
                    if (dfs(s, p, ++i, j + 2)) return true;
                }
                return false;
            } else {
                if (p[j] != '.' && s[i] != p[j]) return false;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        return dfs(s, p, 0, 0);
    }
};
```
**solution 3**
```cpp
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &s, string &p, int i, int j) {
        if (m[i][j] != 0) return m[i][j];
        while (i < M && j < N) {
            if (j + 1 < N && p[j + 1] == '*') {
                do {
                    m[i][j] = dfs(s, p, i, j + 2);
                    if (m[i][j] == 1) return 1;
                    if (p[j] == '.' || s[i] == p[j]) ++i;
                    else return m[i][j] = -1;
                } while (i < M);
            } else {
                if (p[j] != '.' && s[i] != p[j]) return m[i][j] = -1;
                ++i, ++j;
            }
        }
        if (i == M) {
            while (j + 1 < N && p[j + 1] == '*') j += 2;
        }
        return i == M && j == N ? 1 : -1;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s, p, 0, 0) == 1;
    }
};
```
**solution 4**
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (j < N && p[j] == '*') continue; // the next element is '*', skip the current one
                if (p[j - 1] == '*') {
                    int k = i;
                    do {
                        if (dp[i][j] = dp[k][j - 2]) break;
                        if (k > 0 && (p[j - 2] == '.' || s[k - 1] == p[j - 2])) --k;
                        else break;
                    } while (k >= 0);
                } else if (i - 1 >= 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[M][N];
    }
};
```

**solution 5**
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[M][N] = true;
        for (int i = M; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                bool match = i < M && (p[j] == '.' || p[j] == s[i]);
                if (j + 1 < N && p[j + 1] == '*') dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                else dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};
```
