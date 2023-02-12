#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n), s(n);

    for(int i = 0; i < N; i++) cin >> h[i] >> s[i];

    long long ng = 0LL; ok = 1LL<<60;
    vector<long long> t(n);

    while(ng < ok) {
        long long k = (ng+ok)/2;

        bool cdt = true;
        for(int i = 0; i < n; i++) {
            t[i] = (k-h[i])/s[i];
            if(k-h[i] < 0) cdt = false;
        }
        sort(t.begin(), t.end());
        for(int i = 0; i < n; i++) {
            if(t[i] < i) cdt = false;
        }
        if(cdt) ok = k;
        else ng = k+1;
    }
    cout << ok << endl;
}