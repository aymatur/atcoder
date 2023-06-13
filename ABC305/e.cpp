#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

using Graph = vector<vector<int>>;
vector<int> dist;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    Graph G(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int p[200009], h[200009];
    for (int i = 0; i < K; i++) {
        cin >> p[i] >> h[i];
        p[i]--;
    }

    priority_queue<pair<int, int>> Q;

    dist.assign(N, -1);

    for (int i = 0; i < K; i++) {
        dist[p[i]] = h[i];
        Q.push(make_pair(h[i], p[i]));
    }

    while(!Q.empty()) {
        auto [x, v] = Q.top();
        Q.pop();
        if (dist[v] != x) continue;
        for (auto next_v : G[v]) {
            if (dist[next_v] < x-1) {
                dist[next_v] = x-1;
                Q.push(make_pair(x-1, next_v));
            }
        }
    }

    int ans = 0;
    vector<int> vis;
    for (int i = 0; i < N; i++) {
        if(dist[i]>=0) {
            ans++;
            vis.push_back(i);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < (int)vis.size(); i++) {
        vis[i]++;
        cout << vis[i] << " ";
    }
    cout << endl;
}