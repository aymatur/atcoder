#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    vector<vector<long long>> dp(N, vector<long long>(N, INF));
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        --a, --b;
        dp[a][b] = t;
        dp[b][a] = t;
    }

    for (int v = 0; v < N; v++) dp[v][v] = 0;

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < N; i++) {
        long long max_time = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            max_time = max(max_time, dp[i][j]);
        }
        ans = min(ans, max_time);
    }
    cout << ans << endl;
}