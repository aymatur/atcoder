#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

using Graph = vector<vector<int>>;
vector<int> dist;
vector<bool> vis;

int N, M;

int main() {
    cin >> N >> M;
    vis.assign(N+1,false);

    auto get = [&] {
        int k;
        cin >> k;
        vector<int> res(k);
        for (int i = 0; i < k; i++) cin >> res[i];
        return res;
    }

    auto dfs = [&] (auto dfs, int v) -> bool {
        if (v == n) return true;
        vis[v] = true;
        vector<int> to = get();
        for (int u : to) {
            if (vis[u]) continue;
            cout << u << endl;
            if (dfs(dfs, u)) return true;
            cout << v << endl;
            get();
        }
        return false;
    };
    dfs(dfs, 1);
    return 0;
}