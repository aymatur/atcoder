#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmin(T& a, T b) { if(a > b) a = b; }

const long long INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;
    int D[N];
    int C[M];
    for (int i = 0; i < N; i++) cin >> D[i];
    for (int i = 0; i < M; i++) cin >> C[i];

    vector<vector<long long>> dp(M+1, vector<long long>(N+1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][j+1], dp[i][j] + D[j]*C[i]);
        }
    }
    long long ans = INF;
    for (int i = 1; i <= M; i++) {
        chmin(ans, dp[i][N]);
    }
    cout << ans << endl;
}