#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    long long sum[200009];
    sum[0] = 0;
    for (int i = 1; i < N; i++) {
        if (i % 2 != 0) sum[i] = sum[i-1];
        else sum[i] = sum[i-1] + A[i] - A[i-1];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        auto posl = lower_bound(A.begin(), A.end(), l);
        int intPosl = posl - A.begin();
        auto posr = lower_bound(A.begin(), A.end(), r);
        int intPosr = posr - A.begin();
        long long ans = 0;
        if (intPosl % 2 == 0) ans += (A[intPosl] - l);
        if (intPosr % 2 == 0) ans += (r - A[intPosr-1]);
        ans += (sum[intPosr-1]-sum[intPosl]);
        cout << ans << endl;
    }
    
}