## longest subsstring without repreating character
**solution 1**
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        unordered_set<char> st;
        while (j < s.size()) {
            while (j < s.size() && !st.count(s[j])) st.insert(s[j++]);
            ans = max(ans, j - i);
            while (i < j && s[i] != s[j]) st.erase(s[i++]);
            ++i;
            ++j;
        }
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> m(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] > start) start = m[s[i]];
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
```
**solution 3**
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, cnt = 0, ans = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 1) cnt++;
            while (cnt) {
                if (m[s[i++]]-- == 2) cnt--;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```
