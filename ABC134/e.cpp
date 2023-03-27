#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const long long INF = 1LL << 60;

template<class T> int LIS(vector<T> a, bool is_strong = true) {
    const T INF = 1<<30;
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; i++) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    int N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    reverse(A.begin(), A.end());
    cout << LIS(A, false) << endl;
}