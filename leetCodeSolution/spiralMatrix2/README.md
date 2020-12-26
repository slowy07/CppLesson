## sprial matrix 2 (easy)

**solution 1**
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0, d = 1; i < n / 2; ++i) {
            int len = n - 2 * i - 1;
            for (int j = 0; j < len; ++j) ans[i][i + j] = d++;
            for (int j = 0; j < len; ++j) ans[i + j][n - i - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - 1][n - i - j - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - j - 1][i] = d++;
        }
        if (n % 2) ans[n / 2][n / 2] = n * n;
        return ans;
    }
};
```
