#include <iostream>
using namespace std;

long long MOD = 1e9 + 7;
pair<long long, long long> fib (long long n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    long long c = (p.first * (((2 * p.second)%MOD - p.first)%MOD))%MOD;
    long long d = ((p.first * p.first)%MOD + (p.second * p.second)%MOD)%MOD;
    if (n & 1)
        return {d, (c + d)%MOD};
    else
        return {c, d};
}

int main() {
    long long n;
    cin >> n;

    cout << fib(n).first << endl;
    return 0;
}
