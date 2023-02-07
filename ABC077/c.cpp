#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long A[100009], B[100009], C[100009];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        long long a = lower_bound(A, A + N, B[i]) - A;
        long long c = N - (upper_bound(C, C + N, B[i]) - C);
        ans += a * c;
    }

    cout << ans << endl;
    return 0;

}