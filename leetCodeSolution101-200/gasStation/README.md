## gas station (medium)

**solution 1**
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minVal = INT_MAX, tank = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            tank += gas[i] - cost[i];
            if (tank < minVal) {
                minVal = tank;
                ans = i;
            }
        }
        return tank >= 0 ? (ans + 1) % N : -1;
    }
};
```

**solution 2 greedy**
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, total = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            total += gas[i] - cost[i];
            if ((tank += gas[i] - cost[i]) < 0) {
                tank = 0;
                ans = i + 1;
            }
        }
        return total < 0 ? -1 : ans;
    }
};
```
