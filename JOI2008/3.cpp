#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    P.push_back(0);
    vector<long long> S;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S.push_back(P[i] + P[j]);
        }
    }
    sort(S.begin(), S.end());

    long long res = 0;
    for (long long a : S) {
        auto it = upper_bound(S.begin(), S.end(), M - a);
        if (it == S.begin()) continue;
        cout << "it" << endl;
        cout << *it << endl;
        --it;
        cout << "--it" << endl;
        cout << *it << endl;
        res = max(res, a + *it);
    }

    cout << res << endl;
}