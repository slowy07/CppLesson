## permutation sequence (medium)

**solution 1 brute force**
```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 0; i < n; ++i) s += ('1' + i);
        while (--k) next_permutation(s.begin(), s.end());
        return s;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        string ans;
        for (int i = 1; i <= n; ++i) {
            fac *= i;
            ans += '0' + i;
        }
        --k;
        for (int i = 0; i < n; ++i) {
            fac /= n - i;
            int j = k / fac + i, tmp = ans[j];
            for (; j > i; --j) ans[j] = ans[j - 1];
            ans[j] = tmp;
            k %= fac;
        }
        return ans;
    }
};
```
