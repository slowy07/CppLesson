## N queen2 (hard)

**solution 1**
```cpp
class Solution {
private:
    int answer = 0;
public:
    int totalNQueens(int n) {
        vector<int> rows(n, -1);
        helper(rows, 0, n);
        return answer;
    }

    void helper(vector<int>& rows, int row, int n) {
        if (row == n) {
            answer++; return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(rows, row, i)) {
                rows[row] = i;
                helper(rows, row + 1, n);
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
};
```
