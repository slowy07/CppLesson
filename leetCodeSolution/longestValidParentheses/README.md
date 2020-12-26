## longest valid parentheses (hard)

**solution 1**
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size() + 1, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') continue;
            int start = i - dp[i] - 1;
            if (start >= 0 && s[start] == '(')
                dp[i + 1] = dp[i] + 2 + dp[start];
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};
```

**solution 2**
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && st.top() != -1 && s[st.top()] == '(') {
                st.pop();
                ans = max(ans, i - st.top());
            } else st.push(i);
        }
        return ans;
    }
};
```

**solution 3**
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (right > left) left = right = 0;
        }
        left = 0, right = 0;
        for (int i = N - 1; i >= 0; --i) {
            left += s[i] == '(';
            right += s[i] == ')';
            if (left == right) ans = max(ans, left + right);
            else if (left > right) left = right = 0;
        }
        return ans;
    }
};
```
