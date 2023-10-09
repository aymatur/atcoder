#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<long long>> dp(N, vector<long long>(21, 0));
    dp[0][a[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0) dp[i][j] += dp[i-1][j-a[i]];
            if (j + a[i] <= 20) dp[i][j] += dp[i-1][j+a[i]];
        }
    }
    cout << dp[N-2][a[N-1]] << endl;
}