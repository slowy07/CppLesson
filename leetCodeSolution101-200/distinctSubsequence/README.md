## distinct subsequence (hard)

**solution 1 DP top-down (DFS + memo)**
```cpp
class Solution {
private:
    string S;
    string T;
    vector<vector<int>> v;
    int dfs(int start, int index) {
        if (index == T.size()) {
            return 1;
        }
        if (start >= S.size()) return 0;
        if (v[start][index] != -1) return v[start][index];
        int cnt = 0;
        for (int i = start; i < S.size(); ++i) {
            if (S[i] != T[index]) continue;
            int c = dfs(i + 1, index + 1);
            cnt += c;
        }
        v[start][index] = cnt;
        return cnt;
    }
public:
    int numDistinct(string s, string t) {
        S = s;
        T = t;
        v = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0);
    }
};
```
**solution 2 2-d DP**
```cpp
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<LL>> dp(M + 1, vector<LL>(N + 1, 0));
        for (int i = 0; i <= M; ++i) dp[i][0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[M][N];
    }
};
```
