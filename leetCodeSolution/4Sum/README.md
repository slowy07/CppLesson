## 4sum (medium)

**soltion 1**

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        int N = A.size();
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            for (int j = i + 1; j < N; ++j) {
                if (j > i + 1 && A[j] == A[j - 1]) continue;
                int t = target - A[i] - A[j];
                for (int p = j + 1, q = N - 1; p < q; ) {
                    if (A[p] + A[q] == t) {
                        ans.push_back({ A[i], A[j], A[p++], A[q--] });
                        while (p < q && A[p] == A[p - 1]) ++p;
                        while (p < q && A[q] == A[q + 1]) --q;
                    } else if (A[p] + A[q] < t) ++p;
                    else --q;
                }
            }
        }
        return ans;
    }
};
```