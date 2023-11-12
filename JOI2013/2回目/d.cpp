#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
template<class T> void chmax(T& a, T b) {if (a < b) a = b;}
int main() {
    int D, N;
    cin >> D >> N;
    vector<int> T(D);
    for (int i = 0; i < D; i++) cin >> T[i];
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < D; i++) cin >> A[i] >> B[i] >> C[i];
    vector<vector<long long>> dp(D, vector<long long>(N, 0));
    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            if (A[j] > T[i] || T[i] > B[j]) continue;
            for (int k = 0; k < N; k++) {
                if (A[j] > T[i-1] || T[i-1] > B[j]) continue; 
                chmax(dp[i][j], dp[i-1][k] + abs(C[j] - C[k]));
                cout << dp[i][j] << endl;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        chmax(ans, dp[D-1][i]);
        cout << ans << endl;
    }
    cout << ans << endl; 
}