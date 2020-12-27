## add binary (easy)

**solution 1**
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans += '0' + (carry & 1);
            carry >>= 1;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```
