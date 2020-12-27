class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (j - 2 < 0 || A[j - 2] != A[i]) A[j++] = A[i];
        }
        return j;
    }
};
