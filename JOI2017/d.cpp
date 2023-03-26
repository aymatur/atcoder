#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    vector<int> m(M);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
        sum[p[i]][i+1]++;
        m[p[i]]++;
    }
    vector<vector<int>> sum(20, vector<int>(110000, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sum[i][j+1] += sum[i][j];
        }
    }
    vector<int> dp(1 << M, 999999999);
    dp[0] = 0;
    for (int i = 0; i < (1 << M); i++) {
        int pos = 0;
        for (int j = 0; j < M; j++) if (i & (1 << j)) pos += m[j];
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) continue;
            dp[i+(1<<j)] = min(dp[i+(1<<j)], dp[i]+m[j]-sum[j][pos+m[j]]+sum[j][pos]);
        }
    }

}