#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
vector<bool> seen;
vector<long long> dist;

void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dist[next_v] += dist[v];
        dfs(G, next_v);
    }
}

int main() {

    int N, Q;
    cin >> N >> Q;
    Graph G(N+1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N+1, false);
    dist.assign(N+1, 0);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        dist[p] += x;
    }

    dfs(G, 1);

    for (int i = 1; i <= N-1; i++){
      cout << dist[i] << " ";
    }
    cout << dist[N] << endl;
}