class Solution {
    double myPow(double x, long n) {
        if (n < 0) return 1 / myPow(x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        return myPow(myPow(x, n / 2), 2) * (n % 2 ? x : 1);
    }
public:
    double myPow(double x, int n) {
        return myPow(x, (long)n);
    }
};
