## valid number (hard)
**solution 1**
```cpp
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, N = s.size();
        while (i < N && s[i] == ' ') ++i;
        if (i < N && (s[i] == '+' || s[i] == '-')) ++i;
        bool digitFound = false;
        while (i < N && isdigit(s[i])) { ++i; digitFound = true; }
        if (i < N && s[i] == '.') ++i;
        while (i < N && isdigit(s[i])) { ++i; digitFound = true; }
        if (!digitFound) return false;
        if (i < N && s[i] == 'e') {
            ++i;
            if (i < N && (s[i] == '+' || s[i] == '-')) ++i;
            bool expFound = false;
            while (i < N && isdigit(s[i])) { ++i; expFound = true; }
            if (!expFound) return false;
        }
        while (i < N && s[i] == ' ') ++i;
        return i == N;
    }
};
```
