class Solution {
public:
    int minCut(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        for(int i = 0; i < n; i++)
            dp[i][i] = true;

        for(int i = 0; i < n-1; i++)
            if(s[i] == s[i+1])
                dp[i][i+1] = true;

        for(int len = 2; len < n; len++)
        {
            for(int i = 0; i < n-len; i++)
            {
                int j = len+i;
                if(s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
            }
        }

        vector<int> cuts(n);
        for(int i = 0; i < n; i++)
        {
            if(dp[0][i])
            {
                cuts[i] = 0;
            }
            else
            {
                int temp = i;
                for(int j = 0; j < i; j++)
                {
                    if(dp[j+1][i] && temp > cuts[j]+1)
                        temp = cuts[j]+1;
                }
                cuts[i] = temp;
            }
        }
        return cuts[n-1];
    }
};
