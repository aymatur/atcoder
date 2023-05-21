#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int Q;
    bool prime[1000000];

    cin >> Q;
    int l[1000000];
    int r[1000000];

    int max_r = 0;

    for (int i = 0; i < Q; i++) {
        int lin, rin;
        cin >> lin >> rin;
        l[i] = lin;
        r[i] = rin;
        max_r = max(max_r, rin);
    }

    for (int i = 2; i <= max_r; i++) prime[i] = true;

    for (int i = 2; i * i <= max_r; i++) {
        if (prime[i] == true) {
            for (int x = 2*i; x <= max_r; x += i) prime[x] = false;
        }
    }

    vector<int> c(100002, 0);

    for (int i = 3; i <= max_r; i += 2) {
        if (prime[i] && prime[(i+1)/2]) c[i]++;
    }

    for (int i = 3; i <= max_r; i += 1) c[i] += c[i-1];

    for (int i = 0; i < Q; i++) {
        cout << c[r[i]]-c[l[i]-1] << endl;
    }
}