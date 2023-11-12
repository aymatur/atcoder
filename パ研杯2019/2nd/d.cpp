#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> void chmin(T& a, T b) {if (a > b) a = b; }; 
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    int sNum[N][4] = {0};
    vector<char> pat{'R','B','W','#'};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            char s;
            cin >> s;
            auto it = find(pat.begin(), pat.end(), s);
            int index = distance(pat.begin(), it);
            sNum[j][index]++;
        }
    }
    vector<vector<long long>> dp(N, vector<long long>(3, INF));
    dp[0][0] = 5 - sNum[0][0];
    dp[0][1] = 5 - sNum[0][1];
    dp[0][2] = 5 - sNum[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmin(dp[i][j], dp[i-1][k] + 5 - sNum[i][j]);
            }
        }
    }
    long long ans = INF;
    for(int i = 0; i < 3; i++) chmin(ans, dp[N-1][i]);
    cout << ans << endl;
}