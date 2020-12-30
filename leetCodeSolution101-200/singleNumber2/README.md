## single number 2 (medium)


**solution 1 bit manipulation**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (unsigned n : nums) {
                cnt = (cnt + ((n >> i) & 1)) % 3;
            }
            ans |= cnt << i;
        }
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int n : nums) {
            high ^= low & n;
            low ^= n;
            unsigned mask = ~(high & low);
            high &= mask;
            low &= mask;
        }
        return low;
    }
};
```
