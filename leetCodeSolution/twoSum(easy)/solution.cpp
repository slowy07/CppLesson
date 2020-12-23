class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        vector<vector<int>> v;
        int N = A.size(), L = 0, R = N - 1;
        for (int i = 0; i < N; ++i) v.push_back({ A[i], i });
        sort(begin(v), end(v), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        while (L < R) {
            int sum = v[L][0] + v[R][0];
            if (sum == target) return { v[L][1], v[R][1] };
            if (sum < target) ++L;
            else --R;
        }
        return {};
    }
};
