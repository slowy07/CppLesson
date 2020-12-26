class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 0; i < n; ++i) s += ('1' + i);
        while (--k) next_permutation(s.begin(), s.end());
        return s;
    }
};
