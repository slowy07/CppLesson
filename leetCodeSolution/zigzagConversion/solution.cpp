class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int N = s.size(), d = (numRows - 1) * 2;
        string ans;
        for (int i = 0; i < numRows; ++i) {
            int w = 2 * i;
            for (int j = i; j < N;) {
                ans += s[j];
                w = d - w;
                if (!w) w = d;
                j += w;
            }
        }
        return ans;
    }
};
