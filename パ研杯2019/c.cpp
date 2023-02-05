#include <iostream>
#include <cmath>
using namespace std;

int N, M, A[109][109];

int main() {
    cin >> N >> M;
    for(int n = 1; n <= N; n++) {
        for(int m = 1; m <= M; m++) {
            cin >> A[n][m];
        }
    }
    long long ans = 0;
    long long sum[109][109];
    for(int m1 = 1; m1 < M; m1++) {
        for(int m2 = m1 + 1; m2 <= M; m2++) {
            for(int n = 1; n <= N; n++) {
                sum[m1][m2] += max(A[n][m1], A[n][m2]);
            }
            if(ans < sum[m1][m2]) ans = sum[m1][m2];
        }
    }
    cout << ans << endl;
    return 0;
}