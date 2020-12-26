## combination sum (medium)

**solution 1 DFS**
```cpp
class Solution {
    vector<vector<int>> dfs(vector<int>& A, int target, int start) {
        if (!target) return {{}};
        if (start == A.size()) return {};
        int n = A[start];
        auto ans = dfs(A, target, start + 1);
        if (target >= n) {
            auto tmp = dfs(A, target - n, start);
            for (auto v : tmp) {
                v.push_back(n);
                ans.push_back(v);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        return dfs(A, target, 0);
    }
};
```

**solution 2 DFS**
```cpp
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &c, int t, int start, vector<int> &v) {
        if (!t) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < c.size() && t >= c[i]; ++i) {
            v.push_back(c[i]);
            dfs(c, t - c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(candidates, target, 0, v);
        return res;
    }
};
```
