## minimum window substring (hard)

**solution 1 two pointers**
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0, i = 0, j = 0, S = s.size(), T = t.size();
        int minLen = INT_MAX, begin = -1;
        unordered_map<char, int> m, seen;
        for (char c : t) m[c]++;
        while (j < S) {
            for (; j < S && cnt != T; ++j) {
                if (m.find(s[j]) == m.end()) continue;
                if (++seen[s[j]] <= m[s[j]]) ++cnt;
            }
            for (; cnt == T; ++i) {
                if (m.find(s[i]) == m.end()) continue;
                if (j - i < minLen) {
                    minLen = j - i;
                    begin = i;
                }
                if (--seen[s[i]] < m[s[i]]) --cnt;
            }
        }
        return begin == -1 ? "" : s.substr(begin, minLen);
    }
};
```
**solution 2 template**
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) ++m[c];
        int begin = 0, end = 0, head = 0, cnt = t.size(), len = INT_MAX;
        while (end < s.size()) {
            if (m[s[end++]]-- > 0) --cnt;
            while (!cnt) {
                if (end - begin < len) len = end - (head = begin);
                if (m[s[begin++]]++ == 0) ++cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};
```
