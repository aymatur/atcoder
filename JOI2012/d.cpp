#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(K), b(K);
    vector<int> p(101, -1);
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        p[a[i]] = b[i];
    }

    long long dp[101][3][3] = {0};

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                vector<int> cs = {0, 1, 2};
                if (p[i] >= 0) cs = {p[i]};
                for (int c : cs) {
                    if (i >= 2 && j == k && k == c) continue;
                    dp[i+1][k][c] += dp[i][j][k];
                    dp[i+1][k][c] %= 10000;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
        ans += dp[N][i][j];
        ans %= 10000;
    }
    cout << ans << endl;
}