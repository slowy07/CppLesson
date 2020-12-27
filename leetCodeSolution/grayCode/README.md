## gray code (medium)

**solution 1**
```cpp
class Solution {
private:
    inline int toggle(int n, int i) {
        return n ^ (1 << i);
    }
    int next(int n, unordered_set<int> s) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = toggle(n, i);
            if (s.find(ans) == s.end()) break;
        }
        return ans;
    }
public:
    vector<int> grayCode(int n) {
        unordered_set<int> s{0};
        vector<int> ans(pow(2, n), 0);
        for (int i = 1; i < ans.size(); ++i) {
            s.insert(ans[i] = next(ans[i - 1], s));
        }
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        int N = (1 << n);
        vector<int> ans(N, 0);
        for (int i = 0; true; ++i) {
            int j = (1 << i), d = (1 << (i + 1));
            if (j >= N) break;
            for (; j < N; j += 2 * d) {
                for (int k = j; k < N && k < j + d; ++k) ans[k] |= (1 << i);
            }
        }
        return ans;
    }
};
```
