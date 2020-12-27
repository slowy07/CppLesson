## searched in rotated sorted array (medium)

**solution 1**
```cpp
class Solution {
    int findStart(vector<int> &A) {
        int L = 0, R = A.size() - 1;
        while (L + 1 < R) {
            if (A[L] < A[R]) return L;
            int M = (L + R) / 2;
            if (A[M] > A[R]) L = M + 1;
            else if (A[M] < A[R] || (A[M] == A[R] && A[L] > A[R])) R = M;
            else {
                int k = L;
                while (k < R && A[L] == A[k]) ++k;
                if (k == R) return L;
                if (A[k] < A[L]) return k;
                L = k + 1;
            }
        }
        return A[L] < A[R] ? L : R;
    }
public:
    bool search(vector<int>& A, int T) {
        if (A.empty()) return false;
        int start = findStart(A), N = A.size(), L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2, mid = (start + M) % N;
            if (A[mid] == T) return true;
            if (A[mid] < T) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[0] > A[M]) {
                if (target > A[M]) {
                    if (target <= A.back()) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            } else if (A[0] < A[M]) {
                if (target > A[M]) L = M + 1;
                else {
                    if (target >= A[0]) R = M - 1;
                    else L = M + 1;
                }
            } else if (A[L] == target) return true;
            else ++L;
        }
        return false;
    }
};
```
