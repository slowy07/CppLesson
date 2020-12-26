## spiral matrix (medium)


**solution 1**
```cpp
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<int> ans;
    int M = matrix.size(), N = matrix[0].size();
    for (int i = 0; ans.size() < M * N; ++i) {
      for (int j = i; j < N - i; ++j) ans.push_back(matrix[i][j]);
      for (int j = i + 1; j < M - i; ++j) ans.push_back(matrix[j][N - i - 1]);
      for (int j = N - i - 2; M - i - 1 != i && j >= i; --j) ans.push_back(matrix[M - i - 1][j]);
      for (int j = M - i - 2; N - i - 1 != i && j > i; --j) ans.push_back(matrix[j][i]);
    }
    return ans;
  }
};
```

**solution 2**
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        int M = matrix.size(), N = matrix[0].size(), xl = 0, xh = M - 1, yl = 0, yh = N - 1;
        while (xl <= xh && yl <= yh) {
            int x = xl, y = yl;
            if (xl == xh) {
                while (y <= yh) ans.push_back(matrix[x][y++]);
                break;
            } else if (yl == yh) {
                while (x <= xh) ans.push_back(matrix[x++][y]);
                break;
            } else {
                while (y < yh) ans.push_back(matrix[x][y++]);
                --yh;
                while (x < xh) ans.push_back(matrix[x++][y]);
                --xh;
                while (y > yl) ans.push_back(matrix[x][y--]);
                ++yl;
                while (x > xl) ans.push_back(matrix[x--][y]);
                ++xl;
            }
        }
        return ans;
    }
};
```
**solution 3**
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        vector<int> ans;
        int M = A.size(), N = A[0].size(), i = 0, j = 0, lv = 0;
        for (; ans.size() < M * N; ++lv) {
            for (int k = lv; k < N - lv; ++k) ans.push_back(A[i][j++]);
            --j, ++i;
            for (int k = lv; k < M - 1 - lv; ++k) ans.push_back(A[i++][j]);
            --i, --j;
            if (ans.size() == M * N) break;
            for (int k = lv; k < N - 1 - lv; ++k) ans.push_back(A[i][j--]);
            ++j, --i;
            for (int k = lv; k < M - 2 - lv; ++k) ans.push_back(A[i--][j]);
            ++i, ++j;
        }
        return ans;
    }
};
```
