## largest rectangle in histogram (hard)

**solution 1 monotonic stack**
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.insert(A.begin(), 0);
        A.push_back(0);
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N), s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.back()] > A[i]) {
                right[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[s.back()] > A[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]);
        return ans;
    }
};
```
**solution 2 monotonic stack**
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int N = A.size(), ans = 0;
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] >= A[i]) {
                int h = A[s.top()];
                s.pop();
                int j = s.size() ? s.top() : -1;
                ans = max(ans, h * (i - j - 1));
            }
            s.push(i);
        }
        return ans;
    }
};
```
**solution 3 DP**
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N);
        left[0] = -1;
        right[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && A[j] >= A[i]) j = left[j];
            left[i] = j;
        }
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = right[j];
            right[i] = j;
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]);
        return ans;
    }
};
```
