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
