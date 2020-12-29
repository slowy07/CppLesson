class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};
