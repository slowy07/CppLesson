## letter combination of a phone number (medium)

**solution 1**
```cpp
class Solution {
    vector<string> m{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(string &digits, int start, string &str) {
        if (start == digits.size()) {
            ans.push_back(str);
            return;
        }
        for (char c : m[digits[start] - '2']) {
            str.push_back(c);
            dfs(digits, start + 1, str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string str;
        dfs(digits, 0, str);
        return ans;
    }
};
```
**solution 2**
```cpp

class Solution {
private:
    vector<string> M{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans{""};
        for (char c : digits) {
            vector<string> next;
            string m = M[c - '2'];
            for (string s : ans) {
                for (char c : m) {
                    next.push_back(s + c);
                }
            }
            ans = next;
        }
        return ans;
    }
};
```