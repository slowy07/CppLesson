## jump game (medium)

**solution 1 greedy**
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) return false;
            last = max(last, i + nums[i]);
        }
        return true;
    }
};
```
```cpp
class Solution {
public:
    bool canJump(vector<int>& A) {
        int last = 0;
        for (int i = 0; i <= last; ++i) {
            last = max(last, i + A[i]);
            if (last >= A.size() - 1) return true;
        }
        return false;
    }
};
```
