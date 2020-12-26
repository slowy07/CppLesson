class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        int N = A.size();
        for (int i = 0; i < N - 2; ++i) {
            if (i && A[i] == A[i - 1]) continue;
            int L = i + 1, R = N - 1;
            while (L < R) {
                int sum = A[i] + A[L] + A[R];
                if (sum == 0) ans.push_back({ A[i], A[L], A[R] });
                if (sum >= 0) {
                    --R;
                    while (L < R && A[R] == A[R + 1]) --R;
                }
                if (sum <= 0) {
                    ++L;
                    while (L < R && A[L] == A[L - 1]) ++L;
                }
            }
        }
        return ans;
    }
};