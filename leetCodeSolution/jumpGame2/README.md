## jump game II (hard)

**solution 1**
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> endsAt(1, 0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            int step = lower_bound(endsAt.begin(), endsAt.end(), i) - endsAt.begin();
            int next = i + nums[i];
            if (step == endsAt.size() - 1) {
                if (next > endsAt[step]) endsAt.push_back(next);
            } else {
                 if (next > endsAt[step + 1]) endsAt[step + 1] = next;
            }
        }
        return lower_bound(endsAt.begin(), endsAt.end(), nums.size() - 1) - endsAt.begin();
    }
};
```

**solution 2 (bfs greedy)**
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, jumpsEnd = 0, furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == jumpsEnd) {
                ++jumps;
                jumpsEnd = furthest;
            }
        }
        return jumps;
    }
};
```
