#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    long long a[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    long long sum[N+1];
    sum[0] = 0;
    for (int i = 1; i < N+1; i++) sum[i] = sum[i-1] + a[i-1];
    vector<long long> ans(N, 0);
    for (int k = 1; k <= N; k++) {
        for (int i = k; i <= N; i++) {
            ans[k-1] = max(ans[k-1], sum[i]-sum[i-k]);
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
}