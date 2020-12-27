## search 2d matrix (medium)


**solution 1 binary search**
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M][0] == target) return true;
            if (A[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        if (R == -1) return false;
        int row = R;
        L = 0, R = A[0].size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[row][M] == target) return true;
            if (A[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```
**solution 2 binary search**
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L <= R) {
            int mid = (L + R) / 2, val = A[mid / N][mid % N];
            if (val == target) return true;
            if (val < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }
};
```
