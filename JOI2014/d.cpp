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

    vector<vector<long long>> dp(N, vector<long long>((1 << 3), 0));
    for (int i = 0; i < (1 << 3); i++) {
        bitset<15> bits(i);
        if (bits.test(m[0]) && bits.test(0)) dp[0][i] = 1;

    }
    for (int d = 1; d < N; d++) {
        for (int i = 0; i < (1 << 3); i++) {
            bitset<15> bits(i);
            if (!bits.test(m[d])) continue;
            for (int j = 0; j < (1 << 3); j++) {
                bitset<15> bits2(j);
                if (!bits2.test(m[d])) {
                    if (i & j) {
                        dp[d][i] += dp[d-1][j];
                        dp[d][i] %= 10007;
                    }
                } else {
                    dp[d][i] += dp[d-1][j];
                    dp[d][i] %= 10007;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < (1 << 3); i++) {
        bitset<15> bits(i);
        if (bits.test(m[N-1])) {
            ans += dp[N-1][i];
            ans %= 10007;
            // long long o = dp[N-1][i] % 10007;
            // cout << o << endl;
        }
    }
    cout << ans << endl;
}