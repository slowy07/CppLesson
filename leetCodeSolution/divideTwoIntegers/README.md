## divide two integers (medium)

**solution 1**
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        long m = labs(dividend), n = labs(divisor), res = 0;
        if (m < n) return 0;
        long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p + divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};
```
