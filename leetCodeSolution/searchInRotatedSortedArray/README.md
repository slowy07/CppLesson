## search in rotated sorted array (medium)

**solution 1**
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int L = 0, R = nums.size() - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        if (pivot && target >= nums[0] && target <= nums[pivot - 1]) L = 0, R = pivot - 1;
        else L = pivot, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[M] == target) return M;
            if (target > nums[M]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int N = nums.size(), L = 0, R = N - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        L = 0, R = N - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            int MM = (M + pivot) % N;
            if (nums[MM] == target) return MM;
            if (target > nums[MM]) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```
**solution 3**
```cpp
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[M] > A[R] && (target > A[M] || target < A[L]))
               || (A[M] <= A[R] && (target > A[M] && target <= A[R]))) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```
**solution 4**
```cpp
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[0] <= A[M] && (A[M] < target || target < A[0]))
               || (A[0] > A[M] && target > A[M] && target < A[0])) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
```
