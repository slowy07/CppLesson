class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }

        const int upper = pow(10, n) - 1;
        for (int k = 2; k <= upper; ++k) {
            const int left = pow(10, n) - k;
            auto s = to_string(left);
            reverse(begin(s), end(s));
            const int right = stoi(s);
            const int d = k * k - right * 4;
            if (d < 0) {
                continue;
            }
            if (sqrt(d) == int(sqrt(d)) && k % 2 == int(sqrt(d)) % 2) {
                return (static_cast<uint64_t>(left * pow(10, n)) + right) % 1337;
            }
        }
        return -1;
    }
private:
    long long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoll(to_string(n) + s);
    }
