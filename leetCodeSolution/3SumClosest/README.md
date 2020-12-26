## 3sum closest (medium)
**solution 1**
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int diff = INT_MAX;
        for (int i = 0, N = A.size(); i < N; ++i) {
            int L = i + 1, R = N - 1;
            while (L < R) {
                int sum = A[L] + A[R] + A[i];
                if (sum == target) return target;
                if (abs(target - sum) < abs(diff)) diff = target - sum;
                if (sum > target) --R;
                else ++L;
            }
        }
        return target - diff;
    }
};
```