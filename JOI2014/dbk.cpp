#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        char s;
        cin >> s;
        int add = 0;
        if (s == 'J') add = 0; 
        if (s == 'O') add = 1;
        if (s == 'I') add = 2;
        m[i] = add;
    }

    vector<vector<int>> dp(N, vector<int>(8, 0));
    for (int i = 0; i < (1 << 3); i++) {
        if ((i & (1 << 0)) == 0) continue;
        if ((i & (1 << m[0])) != 0) dp[0][i] = 1;

    }
    for (int d = 1; d < N; d++) {
        for (int i = 0; i < 8; i++) {
            cout << dp[d][i] << endl;
            if ((i & (1 << m[d])) == 0) continue;
            for (int j = 0; j < 8; j++) {
                if (i & j) {
                    dp[d][i] = (dp[d][i] + dp[d-1][j]) % 10007;
                }
            }
            // if ((i & (1 << m[d])) == 0) dp[d][i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        // if ((i & (1 << m[N-1])) != 0) {
            ans = (ans + dp[N-1][i]) % 10007;
        // }
    }
    cout << ans << endl;
}