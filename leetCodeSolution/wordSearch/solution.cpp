class Solution {
    int M, N, dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(vector<vector<char>> &A, string &word, int start, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] != word[start]) return false;
        if (start + 1 == word.size()) return true;
        char c = A[x][y];
        A[x][y] = '\0';
        for (auto &dir : dirs) {
            if (dfs(A, word, start + 1, x + dir[0], y + dir[1])) return true;
        }
        A[x][y] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& A, string word) {
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dfs(A, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
