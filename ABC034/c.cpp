#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long W, H;
long long fact[200009];

long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int i = 0; i < 30; i++) {
        if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
        p *= p; p %= m;
    }
    return Answer;
}

long long Division(long long a, long long b, long long m) {
    return (a * modpow(b, m - 2, m)) % m;
}

long long ncr(int n, int r) {
    return Division(fact[n], fact[r] * fact[n - r] % mod, mod);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = 1LL * i * fact[i - 1] % mod;

    cin >> W >> H;
    cout << ncr(W + H - 2, H - 1) << endl;
    return 0;
}