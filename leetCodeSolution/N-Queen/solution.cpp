class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<int> rows(n, -1);

        helper(0, n, rows, answer);
        return answer;
    }

    void helper(int row, int n, vector<int>& rows, vector<vector<string>>& answer) {
        if (row == n) {
            vector<string> solution = plot(rows);
            answer.push_back(solution); return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(rows, row, i)) {
                rows[row] = i;
                helper(row + 1, n, rows, answer);
                rows[row] = -1;
            }
        }
    }

    bool isValid(vector<int>& rows, int row, int col) {
        for (int i = 0; i < rows.size(); i++) {
            int j = rows[i];

            if (j == -1) continue;

            if (j == col) return false;
            if (i + j == row + col) return false;
            if (i - j == row - col) return false;
        }

        return true;
    }

    vector<string> plot(vector<int>& rows) {
        vector<string> solution;
        int n = rows.size();

        for (int i = 0; i < n; i++) {
            string s = "";

            for (int j = 0; j < n; j++) {
                if (j == rows[i]) s += "Q";
                else s += ".";
            }
            solution.push_back(s);
        }
        return solution;
    }
};
