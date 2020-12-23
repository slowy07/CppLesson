#include <bits/stdc++.h>
using namespace std;

void collatz(int n) {
    while (n > 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (3 * n) + 1;
        }
    }
    cout << n << endl;
}
int main() {
    int n;
    cout << "Enter an integer n to compute the Collatz sequence: ";
    cin >> n;
    collatz(n);
    return 0;
}
