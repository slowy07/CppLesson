## generate parentheses (medium)

**solution 1**

```cpp
class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, string &s) {
        if (!leftCnt && !rightCnt) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s.push_back('(');
            generate(leftCnt - 1, rightCnt, s);
            s.pop_back();
        }
        if (rightCnt > leftCnt) {
            s.push_back(')');
            generate(leftCnt, rightCnt - 1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, n, s);
        return ans;
    }
};
```

**solution 2**
```cpp
class Solution {
private:
    vector<string> ans;
    void generate(int leftCnt, int rightCnt, int i, string &s) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        if (leftCnt) {
            s[i] = '(';
            generate(leftCnt - 1, rightCnt, i + 1, s);
        }
        if (rightCnt > leftCnt) {
            s[i] = ')';
            generate(leftCnt, rightCnt - 1, i + 1, s);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(2 * n, '\0');
        generate(n, n, 0, s);
        return ans;
    }
};
```

**solution 3**
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return { "" };
        auto prev = generateParenthesis(n - 1);
        unordered_set<string> s;
        for (int i = 0; i < prev.size(); ++i) {
            for (int j = 0; j < 2 * n - 1; ++j) {
                s.insert(prev[i].substr(0, j) + "()" + prev[i].substr(j));
            }
        }
        return vector<string>(s.begin(), s.end());
    }
};
```
