#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<int>> dp(N, vector<int>(20, 0));
    dp[0][a[0]]++;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0 && dp[i-1][j] > 0) dp[i][j-a[i]]++;
            if (j + a[i] <= 20 && dp[i-1][j] > 0) dp[i][j+a[i]]++;
        }
    }
    cout << dp[N-2][a[N-1]] << endl;
}