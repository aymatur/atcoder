#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    stable_sort(s.begin(), s.end());
    vector<int> ans(n);
    for(int i = 0; i < n - 1; i++) {
        auto [a,ai] = s[i]
        auto [b,bi] = s[i+1];
        int now = 0;
        while(now < a.size() && now < b.size()) {
            if(a[now] != b[now]) break;
            now++;
        }
        ans[ai] = max(ans[ai], now);
        ans[bi] = max(ans[bi], now);
    }
    for (int i = 0; i < n; i++) cour << ans[i] << '\n';
    return 0;
}