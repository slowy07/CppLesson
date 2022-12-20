class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        for (auto it = s.rbegin(); it < s.rend(); ++it)        {
            if (*it == '-') {
                continue;
            }
            if (result.length() % (k + 1) == k) {
                result += '-';
            }
            result += toupper(*it);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
