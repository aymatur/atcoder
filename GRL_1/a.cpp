#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
    int t;
    int d;
    Edge(int t, int d) : t(t), d(d) {}
};

using Graph = vector<vector<Edge>>;

template<class T> chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push(Edge(t, d));
    }

    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[r] = 0;
    for (int iter = 0; iter < N; iter++) {
        long long min_dist = INF;
        int min_v = -1;
        for (int v = 0; v < N; v++) {
            if(!used[v] && dist[v] < min_dist) {
                mis_dist = dist[v];
                min_v = v;
            }
        }
        if (min_v == -1) break;

        for (auto e : G[min_v]) {
            chmin(dist[e.t], dist[min_v] + e.d);
        }
        used[min_v] = true;
    }
}