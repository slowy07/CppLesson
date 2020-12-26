## longest common prefix (easy)

**solution 1**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        int len = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (strs[i][j] && strs[0][j] && strs[i][j] == strs[0][j]) ++j;
            len = min(len, j);
        }
        return strs[0].substr(0, len);
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        int len = 0;
        while (strs[0][len] && strs.back()[len] && strs[0][len] == strs.back()[len]) ++len;
        return strs[0].substr(0, len);
    }
};
```
**solution 3**
```cpp
class Solution {
private:
    string longestCommonPrefix(vector<string>& strs, int begin, int end) {
        if (begin == end) return "";
        if (begin == end - 1) return strs[begin];
        int mid = (begin + end) / 2, len = 0;
        string left = longestCommonPrefix(strs, begin, mid);
        string right = longestCommonPrefix(strs, mid, end);
        while (left[len] && right[len] && left[len] == right[len]) ++len;
        return left.substr(0, len);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs, 0, strs.size());
    }
};
```
