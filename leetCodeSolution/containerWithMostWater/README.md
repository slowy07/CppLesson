## container with most water (medium)

**solution 1**
```cpp
class Solution {
public:
    int maxArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (!A[i]) continue;
            for (int j = i + 1 + ans / A[i]; j < N; ++j) {
                ans = max(ans, min(A[i], A[j]) * (j - i));
            }
        }
        return ans;
    }
};
```

**solution 2**
```cpp
class Solution {
public:
    int maxArea(vector<int>& A) {
        int ans = 0, L = 0, R = A.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(A[L], A[R]));
            if (A[L] < A[R]) ++L; // Move the smaller edge
            else --R;
        }
        return ans;
    }
};
```