#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
using II = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> denkyu_vec;
    vector<int> denkyu(n);
    cin >> denkyu[0];
    denkyu_vec.push_back(1);
    for (int i = 1; i < n; i++) {
        cin >> denkyu[i];
        int len = *denkyu_vec.rbegin();
        if (denkyu[i] != denkyu[i-1]) {
            *denkyu_vec.rbegin() = len + 1;
        }
        else {
            denkyu_vec.push_back(1);
        }
    }
    int ans = denkyu_vec[0];
    for (int i = 1; i < denkyu_vec.size(); i++) {
        int pre = denkyu_vec[i-1];
        int now = denkyu_vec[i];
        ans = max(ans, pre + now);
        if (i < denkyu_vec.size() - 1) {
            ans = max(ans, pre + now + denkyu_vec[i+1]);
        }
    }
    cout << ans << endl;
}