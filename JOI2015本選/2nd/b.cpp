#include <iostream>
#include <vector>

using namespace std;

long long dp[2100][2100];
int a[2100];
int N;

long long calc(int l, int r, int s) {
    if (~dp[l][r]) return dp[l]][r];
    if (l == r) {
        if (s) return dp[l][r] = 0;
        return dp[l][r] = a[i];
    }
    if (s) {
        if (a[l] > a[r]) {
            return dp[l][r] = calc((l+1)%N, r, 0);
        } else {
            return dp[l][r] = calc(l, (r+N-1)%N, 0);
        }
    }
    return dp[l][r] = max(calc((l+1)%N, r, 1)+a[l], calc(l, (r+N-1)%N, 1)+a[r]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < 2100; i++) {
        for (int j = 0; j < 2100; j++) {
            dp[i][j] = -1;
        }
    }
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        ret = max(ret, calc((i+1)%N, (i+N-1)%N, 1) + b[i]);
    }
    cout << ret << endl;
}