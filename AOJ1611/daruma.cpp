#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int N;
vector<int> w;

int solve() {
    vector<vector<int>> dp(N+1, vector<int>(N+1, -N));
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 0;
        if (i < N) dp[i][i+1] = 0;
    }
    for (int bet = 2; bet <= N; bet++) {
        for (int i = 0; i + bet <= N; i++) {
            int j = i + bet;
            if (dp[i+1][j-1] == j-i-2) chmax(dp[i][j], j-i);
            else chmax(dp[i][j], j-i-2);
        }
        for (int k = i+1; k <= j-1; k++) {
            chmax(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }
    return dp[0][N];
}

int main() {
    while(cin >> N, N) {
        w.resize(N);
        for (int i = 0; i < N; i++) cin >> w[i];
        cout << solve() << endl;
    }
}