class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        for (int i = 2; s.length() < n; ++i) {
            s += string(s[i] -'0', s.back() ^ 3);
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};
