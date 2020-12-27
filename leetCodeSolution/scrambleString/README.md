## scramble string


```
great
/    \
gr    eat
/ \    /  \
g   r  e   at
        / \
       a   t
```
```
rgeat
 /    \
rg    eat
/ \    /  \
r   g  e   at
         / \
        a   t
```
**solution TLE**
```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) return true;
        }
        return false;
    }
};
```
**solution 1**
```cpp
class Solution {
private:
    unordered_map<string, bool> m;
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (s1 > s2) swap(s1, s2);
        string key = s1 + "#" + s2;
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) {
                ans = true;
                break;
            }
        }
        return m[key] = ans;
    }
};
```
**solution 2**
```cpp
class Solution {
private:
    unordered_map<int, bool> m;
    string A, B;
    int getHash (int sa, int ea, int sb, int eb) {
        return sa + ea * 100 + sb * 10000 + eb * 1000000;
    }
    bool isScramble(int sa, int ea, int sb, int eb) {
        int M = ea - sa, N = eb - sb;
        if (M != N) return false;
        int key = getHash(sa, ea, sb, eb);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (!A.compare(sa, ea - sa, B, sb, eb - sb)) ans = true;
        else {
           for (int len = 1; len < M; ++len) {
                if ((isScramble(sa, sa + len, sb, sb + len) && isScramble(sa + len, ea, sb + len, eb))
                   || (isScramble(sa, sa + len, eb - len, eb) && isScramble(sa + len, ea, sb, eb - len))) {
                    ans = true;
                    break;
                }
            }
        }
        return m[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        A = s1;
        B = s2;
        return isScramble(0, s1.size(), 0, s2.size());
    }
};
```
**solution 3**
```cpp
class Solution {
private:
    unordered_map<int, bool> m;
    string A, B;
    int getHash (int sa, int ea, int sb, int eb) {
        return sa + ea * 100 + sb * 10000 + eb * 1000000;
    }
    bool isAnagram(int sa, int ea, int sb, int eb) {
        unordered_map<char, int> cnts;
        for (int i = 0, N = ea - sa; i < N; ++i) {
            cnts[A[sa + i]]++;
            cnts[B[sb + i]]--;
        }
        for (auto &p : cnts) {
            if (p.second) return false;
        }
        return true;
    }
    bool isScramble(int sa, int ea, int sb, int eb) {
        int M = ea - sa, N = eb - sb;
        if (M != N) return false;
        int key = getHash(sa, ea, sb, eb);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (!A.compare(sa, ea - sa, B, sb, eb - sb)) ans = true;
        else if (!isAnagram(sa, ea, sb, eb)) ans = false;
        else {
           for (int len = 1; len < M; ++len) {
                if ((isScramble(sa, sa + len, sb, sb + len) && isScramble(sa + len, ea, sb + len, eb))
                   || (isScramble(sa, sa + len, eb - len, eb) && isScramble(sa + len, ea, sb, eb - len))) {
                    ans = true;
                    break;
                }
            }
        }
        return m[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        A = s1;
        B = s2;
        return isScramble(0, s1.size(), 0, s2.size());
    }
};
```
**solution 4**
```cpp
class Solution {
private:
    bool areAnagram(string &s1, string &s2) {
        unordered_map<char, int> m;
        for (int i = 0; i < s1.size(); ++i) {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for (auto &p : m) {
            if (p.second) return false;
        }
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (!areAnagram(s1, s2)) return false;
        for (int len = 1; len < s1.size(); ++len) {
            if ((isScramble(s1.substr(0, len), s2.substr(0, len))
                && isScramble(s1.substr(len), s2.substr(len)))
               || (isScramble(s1.substr(0, len), s2.substr(s2.size() - len))
                    && isScramble(s1.substr(len), s2.substr(0, s2.size() - len))))
                return true;
        }
        return false;
    }
};
```
