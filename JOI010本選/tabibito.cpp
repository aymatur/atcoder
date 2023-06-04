#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int mod = 100000;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int s[n];
    for (int i = 0; i < n-1; i++) cin >> s[i];
    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    int sum[n];
    sum[0] = 0;
    for (int i = 1; i < n; i++) sum[i] = sum[i-1] + s[i-1];
    int ans = 0;
    int pos = 0;
    for (int i = 0; i < m; i++) {
        ans += abs(sum[pos+a[i]] - sum[pos]);
        ans %= mod;
        pos += a[i];
    }
    cout << ans << endl;
}