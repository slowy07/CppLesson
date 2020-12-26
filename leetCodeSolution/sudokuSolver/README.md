## sudoku solver (hard)

**solution 1**
```cpp
class Solution {
	struct cell
	{
		uint8_t value;

		bitset<10> constraints;
		cell() : value(0), numPossibilities(9),constraints() {};
	};
	array<array<cell,9>,9> cells;
	bool set(int i, int j, int v)
	{
		cell& c = cells[i][j];
		if (c.value == v)
			return true;
		if (c.constraints[v])
			return false;
		c.constraints = bitset<10>(0x3FE);
		c.constraints.reset(v);
		c.numPossibilities = 1;
		c.value = v;

		for (int k = 0; k<9; k++) {
			if (i != k && !updateConstraints(k, j, v))
				return false;
			if (j != k && !updateConstraints(i, k, v))
				return false;
			int ix = (i / 3) * 3 + k / 3;
			int jx = (j / 3) * 3 + k % 3;
			if (ix != i && jx != j && !updateConstraints(ix, jx, v))
				return false;
		}
		return true;
	}
	bool updateConstraints(int i, int j, int excludedValue)
	{
		cell& c = cells[i][j];
		if (c.constraints[excludedValue]) {
			return true;
		}
		if (c.value == excludedValue) {
			return false;
		}
		c.constraints.set(excludedValue);
		if (--c.numPossibilities > 1)
			return true;
		for (int v = 1; v <= 9; v++) {
			if (!c.constraints[v]) {
				return set(i, j, v);
			}
		}
		assert(false);
	}

	vector<pair<int, int>> bt;

	bool findValuesForEmptyCells()
	{
		bt.clear();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!cells[i][j].value)
					bt.push_back(make_pair(i, j));
			}
		}
		sort(bt.begin(), bt.end(), [this](const pair<int, int>&a, const pair<int, int>&b) {
			return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities; });
		return backtrack(0);
	}

	bool backtrack(int k)
	{
		if (k >= bt.size())
			return true;
		int i = bt[k].first;
		int j = bt[k].second;
		if (cells[i][j].value)
			return backtrack(k + 1);
		auto constraints = cells[i][j].constraints;
		array<array<cell,9>,9> snapshot(cells);
		for (int v = 1; v <= 9; v++) {
			if (!constraints[v]) {
				if (set(i, j, v)) {
					if (backtrack(k + 1))
						return true;
				}
				cells = snapshot;
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>> &board) {
		cells = array<array<cell,9>,9>();
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
					return;
			}
		}

		if (!findValuesForEmptyCells())
			return; // sudoku is unsolvable
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (cells[i][j].value)
					board[i][j] = cells[i][j].value + '0';
			}
		}
	}
};
```
