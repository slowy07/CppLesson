class Solution {
    int M, N;
    vector<vector<int>> m;
    bool isMatch(string &s, string &p, int i, int j) {
        if (m[i][j] != -1) return m[i][j];
        int &ans = m[i][j];
        for (; j < N; ++j) {
            if (p[j] != '*' && i >= M) return ans = false;
            if (p[j] == '?') ++i;
            else if (p[j] == '*') {
                while (j + 1 < N && p[j + 1] == '*') ++j;
                for (int k = 0; i + k <= M; ++k) {
                    if (isMatch(s, p, i + k, j + 1)) return ans = true;
                }
            } else if (s[i++] != p[j]) return ans = false;
        }
        return ans = i >= M;
    }
public:
    bool isMatch(string s, string p) {
        M = s.size(), N = p.size();
        m.assign(M + 1, vector<int>(N + 1, -1));
        return isMatch(s, p, 0, 0);
    }
};
