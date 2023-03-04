#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<class T> void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
    int D, N;
    cin >> D >> N;
    int T[D];
    for (int i = 0; i < D; i++) cin >> T[i];
    int A[N], B[N], C[N];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

    vector<vector<long long>> dp(D+1, vector<long long>(N+1, -1));
    for (int i = 0; i < N; i++) if(A[i] <= T[0] && T[0] <= B[i]) dp[0][i] = 0;

    for (int d = 1; d < D; d++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < N; m++) {
                if (dp[d-1][m] == -1) continue; 
                if (A[n] <= T[d] && T[d] <= B[n]) chmax(dp[d][n], dp[d-1][m] + abs(C[n]-C[m]));
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) chmax(ans, dp[D-1][i]);
    cout << ans << endl;
}