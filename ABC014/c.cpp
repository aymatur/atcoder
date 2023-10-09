#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    vector<int> s(1000009, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s[a[i]]++;
        s[b[i]+1]--;
    }
    int count = 0;
    int ans = 0;
    for (int i = 0; i < 1000009; i++) {
        count += s[i];
        ans = max(ans, count);
    }
    cout << ans << endl;
}