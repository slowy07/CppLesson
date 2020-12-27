class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M][0] == target) return true;
            if (A[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        if (R == -1) return false;
        int row = R;
        L = 0, R = A[0].size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[row][M] == target) return true;
            if (A[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        return false;
    }
};
