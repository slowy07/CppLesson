## subsests (medium)


**solution 1 DFS**
```cpp
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int i, vector<int> &s) {
        if (i == A.size()) {
            ans.push_back(s);
            return;
        }
        s.push_back(A[i]); // Pick A[i]
        dfs(A, i + 1, s);
        s.pop_back(); // Skip A[i]
        dfs(A, i + 1, s);
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        dfs(A, 0, s);
        return ans;
    }
};
```
**solution 2 backtrack**
```cpp
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int start, int len, vector<int> &s) {
        if (s.size() == len) {
            ans.push_back(s);
            return;
        }
        for (int i = start; i <= A.size() - len + s.size(); ++i) {
            s.push_back(A[i]);
            dfs(A, i + 1, len, s);
            s.pop_back(); // backtrack
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        for (int len = 0; len <= A.size(); ++len) dfs(A, 0, len, s);
        return ans;
    }
};
```
**solution 3 bit mask**
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        int N = 1 << A.size();
        vector<vector<int>> ans(N);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < N; ++j) {
                if (j >> i & 1) ans[j].push_back(A[i]);
            }
        }
        return ans;
    }
};
```
**solution 4 DP**
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans(1);
        for (int i = 0; i < A.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(A[i]);
            }
        }
        return ans;
    }
};
```
