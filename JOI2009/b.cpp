#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long D,;
int n, m, k[10009];

int main() {
    cin >> D >> n >> m;
    vector<int> d(n+1);
    d[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> k[i];
    }
    d[n] = D;
    sort(d.begin(), d.end());
    int r = 0;
    for(int i = 0; i < m; i++) {
        vector<int>::iterator it = lower_bound(d.begin(), d.end(), k[i]);
        r += min(abs(*it-k[i]), abs(d[it-d.begin()-1]-k[i]));
    }

    cout << r << endl;
    return 0;
}