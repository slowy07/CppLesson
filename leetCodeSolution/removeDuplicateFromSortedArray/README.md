## remove duplicate from sorted arrays (easy)

**solution 1**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        for (int n : A) {
            if (j - 1 < 0 || A[j - 1] != n) A[j++] = n;
        }
        return j;
    }
};
```

**solution 2**
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int i = 0, j = 0, N = A.size();
        while (i < N) {
            A[j++] = A[i++];
            while (i < N && A[i] == A[i - 1]) ++i;
        }
        return j;
    }
};
```
