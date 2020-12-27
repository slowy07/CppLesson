class Solution {
public:
    int climbStairs(int n) {
        int ans = 1, prev = 1;
        while (--n) {
            ans += prev;
            prev = ans - prev;
        }
        return ans;
    }
};
