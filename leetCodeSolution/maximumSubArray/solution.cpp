class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minSum = 0, ans = INT_MIN;
        for (int n : nums) {
            ans = max(ans, n - minSum);
            minSum = min(minSum, n);
        }
        return ans;
    }
};
