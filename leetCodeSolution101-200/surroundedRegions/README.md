## surrounded regions (medium)


**solution 1**
```cpp
class Solution {
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') return;
        board[x][y] = '#';
        for (auto &dir : dirs) dfs(board, x + dir[0], y + dir[1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        for (int i = 0; i < M; ++i) {
            dfs(board, i, 0);
            dfs(board, i, N - 1);
        }
        for (int j = 0; j < N; ++j) {
            dfs(board, 0, j);
            dfs(board, M - 1, j);
        }
        for (auto &row : board) {
            for (auto &cell : row) {
                cell = cell == '#' ? 'O' : 'X';
            }
        }
    }
};
```
**solution 2**
```cpp
class UnionFind {
    vector<int> id, rank;
public:
    UnionFind(int n): id(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            id[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        } else id[y] = x;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    inline int get(int x, int y) { return N * x + y; }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        UnionFind uf(M * N + 1);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 'O') continue;
                if (!i || i == M - 1 || !j || j == N - 1) uf.connect(get(i, j), M * N);
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') continue;
                    uf.connect(get(i, j), get(x, y));
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!uf.connected(get(i, j), M * N)) board[i][j] = 'X';
            }
        }
    }
};
```
