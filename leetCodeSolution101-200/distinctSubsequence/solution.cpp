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
