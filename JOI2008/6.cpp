#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmax(T& a, T b) { if(a < b) {a = b; return true;} else return false; }
template<class T> bool chmin(T& a, T b) { if(a > b) {a = b; return true;} else return false; }
const long long INF = 1LL<<60;

int main() {
    int n, k;
    cin >> n >> k;
    Graph G(n);
    vector<bool> used(n);
    vector<long long> dist(n);
    for (int i = 0; i < k; i++) {
        int h, f, t;
        long long w;
        cin >> h >> f >> t;
        --f; --t;
        if (h == 0) {
            used.assign(n, false);
            dist.assign(n, INF);
            dist[f] = 0;
            for (int iter = 0; iter < n; iter++) {
                long long min_dist = INF;
                int min_v = -1;
                for (int v = 0; v < n; v++) {
                    if (!used[v] && dist[v] < min_dist) {
                        min_dist = dist[v];
                        min_v = v;
                    }
                }
                if (min_v == -1) break;
                for (auto e : G[min_v]) {
                    chmin(dist[e.to], dist[min_v] + e.w);
                }
                used[min_v] = true;
            }
            if (dist[t] == INF) cout << -1 << endl;
            else cout << dist[t] << endl;
        } else {
            cin >> w;
            G[f].push_back(Edge(t, w));
            G[t].push_back(Edge(f, w));
        }
    }
}