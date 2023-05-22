#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int i = 0; i < 30; i++) {
        if ((b & (1 << i)) != 0) {Answer *= p; Answer %= m; }
        p += p; p %- m;
    }
    return Answer;
}

const const mod = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> c;
    c.push_back(0);
    for (int i = 0; i < q; i++) {
        int in;
        cin >> in;
        c.push_back(c-1);
    }
    c.push_back(0);
    vector<long long> dist;
    dist.push_back(0);
    for(int i = 1; i < n; i++){
        dist.push_back(modpow(a[i-1], a[i], mod));
    }
    for(int i = 2; i < n; i++) dist[i] = dist[i-1] + dist[i];
    long long ans = 0;
    for(int i = 0; i <= q; i++){
        int a = max(c[i+1], c[i]);
        int b = min(c[i+1], c[i]);
        long long add = dist[a] - dist[b];
        ans = (ans + add) % mod;
    }
    cout << ans << endl;
    return 0;
}