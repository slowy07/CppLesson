class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int i, N = A.size();
        for (i = 0; i < N; ) {
            if (A[i] == i + 1 || A[i] < 1 || A[i] >= N + 1 || A[i] == A[A[i] - 1]) ++i;
            else swap(A[i], A[A[i] - 1]);
        }
        for (i = 0; i < N && A[i] == i + 1; ++i);
        return i + 1;
    }
};
