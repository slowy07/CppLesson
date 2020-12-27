class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int i = A.size() - 1, carry = 1;
        for (; i >= 0 && carry; --i) {
            carry += A[i];
            A[i] = carry % 10;
            carry /= 10;
        }
        if (carry) A.insert(begin(A), carry);
        return A;
    }
};
