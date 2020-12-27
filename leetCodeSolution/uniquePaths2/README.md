## unique paths 2 (medium)


**solution 1**
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
int dp[m][n];
for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
		else if (i == 0 && j == 0) dp[i][j] = 1;
        else if (i == 0) dp[i][j] = dp[i][j-1];
        else if (j == 0) dp[i][j] = dp[i-1][j];
        else dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
}
return dp[m-1][n-1];
    }
};
```
