#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    int P[100009];
    int A[100009], B[100009], C[100009];

    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> P[i];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> d(100009, 0);
    for (int i = 0; i < M-1; i++) {
        if (P[i] < P[i+1]) {
            d[P[i]]++;
            d[P[i+1]]--;
        } else {
            d[P[i+1]]++;
            d[P[i]]--;
        }
    }
    long long num = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (num == 0 && d[i] == 0) continue;
        num += d[i];
        long long cost = min(num*A[i-1], num*B[i-1]+C[i-1]);
        ans += cost;
    }
    cout << ans << endl;
}