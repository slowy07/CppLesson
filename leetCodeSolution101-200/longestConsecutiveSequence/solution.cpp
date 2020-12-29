class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int n : nums) {
            if (m[n]) continue;
            ans = max(ans, m[n] = m[n - m[n - 1]] = m[n + m[n + 1]] = m[n - 1] + m[n + 1] + 1);
        }
        return ans;
    }
};
