#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000000;

template<class T> void chmin(T& a, T b) { if(a > b) a = b; }

int main() {
    int N;
    cin >> N;

    vector<vector<char>> s(5, vector<char>(N));

    vector<vector<int>> color(N, vector<int>(4, 0));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'R') {color[j][0]++;}
            if (s[i][j] == 'B') {color[j][1]++;}
            if (s[i][j] == 'W') {color[j][2]++;}
            if (s[i][j] == '#') {color[j][3]++;}
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(4, INF));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) chmin(dp[i+1][j], dp[i][k]+5-color[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; i++) chmin(ans, dp[N][i]);
    cout << ans << endl;
}