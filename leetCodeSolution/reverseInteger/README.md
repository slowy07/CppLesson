## reverse integer (easy)

**solution 1**
```cpp
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int r = 0, sign = x >= 0 ? 1 : -1, y = sign * x, p = 1;
        while (y) {
            y /= 10;
            if (y) p *= 10;
        }
        x = sign * x;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((INT_MAX - r) / p < d) return 0;
            r += p * d;
            p /= 10;
        }
        return sign * r;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            int d = x % 10;
            x /= 10;
            if ((r >= 0 && (r > INT_MAX / 10 || INT_MAX - 10 * r < d))
                || (r < 0 && (r < INT_MIN / 10 || INT_MIN - 10 * r > d))) return 0;
            r = r * 10 + d;
        }
        return r;
    }
};
```
