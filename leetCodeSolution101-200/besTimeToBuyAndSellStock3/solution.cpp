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
