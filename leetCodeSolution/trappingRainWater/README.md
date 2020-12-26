## trapping rain water (hard)

**solution 1**
```cpp
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> left(N, 0), right(N, 0);
        for (int i = 1; i < N; ++i) left[i] = max(left[i - 1], A[i - 1]);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 1; i < N - 1; ++i) ans += max(0, min(left[i], right[i]) - A[i]);
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int trap(vector<int>& A) {
        stack<int> s;
        int N = A.size(), ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s.empty() || A[i] > A[s.top()]) s.push(i);
        }
        for (int i = 0; i < N - 1;) {
            int h = A[i];
            if (i == s.top()) {
                s.pop();
                h = A[s.top()];
            }
            int j = i + 1;
            while (j < N && A[j] < h) ans += h - A[j++];
            i = j;
        }
        return ans;
    }
};
```
**solution 3 (two pointers)**
```cpp
class Solution {
public:
    int trap(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0, i = 0, j = N - 1, left = 0, right = 0;
        while (i < j) {
            if (A[i] < A[j]) {
                left = max(left, A[i]);
                ans += left - A[i++];
            } else {
                right = max(right, A[j]);
                ans += right - A[j--];
            }
        }
        return ans;
    }
};
```
